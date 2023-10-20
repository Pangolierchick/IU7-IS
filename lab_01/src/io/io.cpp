#include "io.h"

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

void text::write_to_file(const std::string &s) {
  std::ofstream file(DEFAULT_OUTPUT_FILENAME);

  if (!file.is_open()) {
    throw std::runtime_error("Couldn't open file");
  }

  file << s;
}

std::string text::read_from_file() {
  std::ifstream file(DEFAULT_INPUT_FILENAME);

  if (!file.is_open()) {
    throw std::runtime_error("Couldn't open file");
  }

  std::string s;

  std::getline(file, s);

  return s;
}

std::vector<uint8_t> binary::read_from_file() {
  std::ifstream file(DEFAULT_INPUT_FILENAMEB, std::ios::binary);
  if (!file) {
    throw std::runtime_error("Couldn't open file");
  }

  std::vector<uint8_t> data((std::istreambuf_iterator<char>(file)),
                            std::istreambuf_iterator<char>());
  return data;
}

void binary::write_to_file(const std::vector<uint8_t> &s) {
  std::ofstream file(DEFAULT_OUTPUT_FILENAMEB, std::ios::binary);
  if (!file) {
    throw std::runtime_error("Couldn't open file");
  }

  file.write(reinterpret_cast<const char *>(s.data()), s.size());
  if (!file) {
    throw std::runtime_error("Write error");
  }
}
