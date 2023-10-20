#pragma once

#include <vector>

class Rotor {
 private:
  std::vector<int> r;

 public:
  Rotor() = delete;
  Rotor(std::vector<int> _r) : r(_r) {}

  void shift(void);
  int find(int code);
  void output(void);
  int& operator[](int i) { return this->r.at(i); }

  ~Rotor() = default;
};
