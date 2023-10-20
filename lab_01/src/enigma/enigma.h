#pragma once

#include <vector>

#include "src/rotor/rotor.h"

class Enigma {
public:
  Enigma(const std::vector<int> &_reflector,
         const std::vector<std::vector<int>> &_rotors,
         const std::vector<int> &_commutator)
      : reflector(_reflector), commutator(_commutator) {
    for (auto &r : _rotors) {
      Rotor rotor(r);
      rotors.push_back(rotor);
    }
  }

  void output(void);
  int encrypt_ch(int code);
  std::string encrypt(const std::string &);
  std::vector<uint8_t> encryptb(const std::vector<uint8_t> &);

  ~Enigma() = default;

private:
  std::vector<Rotor> rotors;
  std::vector<int> reflector;
  std::vector<int> commutator;
  int counter = 0;
};
