#pragma once

#include <cstdint>
#include <string>
#include <vector>

#define DEFAULT_OUTPUT_FILENAME "output.txt"
#define DEFAULT_INPUT_FILENAME "input.txt"

#define DEFAULT_OUTPUT_FILENAMEB "output.jpg"
#define DEFAULT_INPUT_FILENAMEB "input.jpg"

namespace text {
void write_to_file(const std::string &s);
std::string read_from_file();
}; // namespace text

namespace binary {
void write_to_file(const std::vector<uint8_t> &s);
std::vector<uint8_t> read_from_file();
} // namespace binary
