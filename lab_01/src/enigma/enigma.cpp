#include "enigma.h"
#include "src/coder/coder.h"

#include <cstdint>
#include <iostream>
#include <vector>

void Enigma::output(void) {
  int r_c = 0;
  for (auto &r : this->rotors) {
    std::cout << "Rotor #" << r_c + 1 << "\n";
    r.output();
    r_c++;
  }

  std::cout << "Reflector:\n";
  for (auto r : this->reflector) {
    std::cout << r << " ";
  }

  std::cout << "\n";
}

int Enigma::encrypt_ch(int code) {
  int new_code = code;

  new_code = this->commutator.at(new_code);

  // NOTE: rotors -> reflector
  for (auto &r : this->rotors) {
    new_code = r[new_code];
  }

  new_code = this->reflector.at(new_code);

  // NOTE: reflector -> rotors
  for (int i = this->rotors.size() - 1; i >= 0; i--) {
    new_code = this->rotors[i].find(new_code);

    if (new_code == -1) {
      return -1;
    }
  }

  new_code = this->commutator.at(new_code);

  int rotor_queue = 1;
  this->counter++;

  for (auto &r : this->rotors) {
    if (this->counter % rotor_queue == 0) {
      r.shift();
    }

    rotor_queue *= this->rotors.size();
  }

  return new_code;
}

std::string Enigma::encrypt(const std::string &s) {
  std::string rs;

  for (auto i : s) {
    rs += decode(encrypt_ch(encode(i)));
  }

  return rs;
}

std::vector<uint8_t> Enigma::encryptb(const std::vector<uint8_t> &b) {
  std::vector<uint8_t> rv;

  int s = 0;
  int e = b.size();

  const char *ec[] = {
      "/",
      "|",
      "\\",
      "-",
  };
  int j = 0;

  for (auto i : b) {
    rv.push_back(encrypt_ch(i));

    if (s % 90000 == 0) {
      std::cout << "Encrypting " << (int)(((float)s / (float)e) * 100) << "/"
                << 100 << " " << ec[j % 4] << "\r";
      std::cout.flush();
      j++;
    }

    s++;
  }
  std::cout << "\nDone\n";

  return rv;
}
