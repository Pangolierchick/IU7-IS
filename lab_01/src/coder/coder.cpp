#include "coder.h"

#include <string>

std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";

char decode(int c) { return alphabet.at(c); }
int encode(char c) { return alphabet.find(c); }
