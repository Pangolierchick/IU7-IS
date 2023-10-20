#include "rotor.h"

#include <iostream>

int Rotor::find(int code) {
  for (int i = 0; i < this->r.size(); i++) {
    if (this->r[i] == code) {
      return i;
    }
  }

  return -1;
}

void Rotor::shift(void) {
  int temp = this->r[this->r.size() - 1];

  for (int i = this->r.size() - 1; i > 0; i--) {
    this->r[i] = this->r[i - 1];
  }

  this->r[0] = temp;
}

void Rotor::output(void) {
  for (auto v : this->r) {
    std::cout << v << " ";
  }

  std::cout << "\n";
}
