#include <iostream>

#include "src/coder/coder.h"
#include "src/enigma/enigma.h"
#include "src/io/io.h"
#include "src/rotor/rotor.h"

std::vector<int> reflector = {
    255, 254, 253, 252, 251, 250, 249, 248, 247, 246, 245, 244, 243, 242, 241,
    240, 239, 238, 237, 236, 235, 234, 233, 232, 231, 230, 229, 228, 227, 226,
    225, 224, 223, 222, 221, 220, 219, 218, 217, 216, 215, 214, 213, 212, 211,
    210, 209, 208, 207, 206, 205, 204, 203, 202, 201, 200, 199, 198, 197, 196,
    195, 194, 193, 192, 191, 190, 189, 188, 187, 186, 185, 184, 183, 182, 181,
    180, 179, 178, 177, 176, 175, 174, 173, 172, 171, 170, 169, 168, 167, 166,
    165, 164, 163, 162, 161, 160, 159, 158, 157, 156, 155, 154, 153, 152, 151,
    150, 149, 148, 147, 146, 145, 144, 143, 142, 141, 140, 139, 138, 137, 136,
    135, 134, 133, 132, 131, 130, 129, 128, 127, 126, 125, 124, 123, 122, 121,
    120, 119, 118, 117, 116, 115, 114, 113, 112, 111, 110, 109, 108, 107, 106,
    105, 104, 103, 102, 101, 100, 99,  98,  97,  96,  95,  94,  93,  92,  91,
    90,  89,  88,  87,  86,  85,  84,  83,  82,  81,  80,  79,  78,  77,  76,
    75,  74,  73,  72,  71,  70,  69,  68,  67,  66,  65,  64,  63,  62,  61,
    60,  59,  58,  57,  56,  55,  54,  53,  52,  51,  50,  49,  48,  47,  46,
    45,  44,  43,  42,  41,  40,  39,  38,  37,  36,  35,  34,  33,  32,  31,
    30,  29,  28,  27,  26,  25,  24,  23,  22,  21,  20,  19,  18,  17,  16,
    15,  14,  13,  12,  11,  10,  9,   8,   7,   6,   5,   4,   3,   2,   1,
    0,
};
std::vector<std::vector<int>> rotors = {
    {
        78,  153, 188, 230, 111, 50,  193, 15,  122, 130, 132, 233, 95,  192,
        134, 22,  222, 65,  155, 216, 58,  250, 121, 206, 147, 52,  143, 170,
        251, 73,  144, 162, 68,  4,   97,  163, 202, 211, 6,   219, 187, 238,
        77,  82,  156, 177, 189, 108, 9,   167, 107, 190, 140, 26,  64,  79,
        127, 91,  234, 191, 24,  90,  17,  125, 32,  203, 30,  62,  57,  201,
        48,  205, 196, 157, 253, 112, 83,  63,  152, 36,  240, 145, 19,  210,
        161, 123, 173, 29,  158, 56,  42,  150, 100, 154, 169, 86,  209, 185,
        61,  151, 248, 226, 89,  96,  46,  41,  124, 20,  225, 255, 93,  12,
        239, 242, 244, 237, 76,  241, 178, 172, 223, 180, 45,  215, 212, 148,
        204, 200, 138, 131, 149, 110, 21,  114, 175, 137, 228, 235, 252, 54,
        11,  38,  164, 103, 16,  60,  174, 229, 181, 160, 171, 10,  81,  214,
        197, 106, 13,  126, 47,  105, 71,  74,  227, 218, 232, 199, 236, 5,
        35,  249, 183, 18,  165, 116, 40,  184, 75,  37,  69,  119, 99,  101,
        217, 87,  44,  49,  159, 254, 139, 182, 224, 88,  55,  0,   72,  117,
        8,   53,  168, 146, 247, 25,  118, 34,  198, 208, 246, 59,  28,  195,
        115, 220, 104, 245, 27,  14,  39,  186, 51,  109, 142, 136, 194, 7,
        221, 80,  213, 94,  231, 70,  66,  67,  33,  43,  141, 176, 120, 92,
        129, 113, 243, 1,   85,  102, 3,   179, 23,  84,  133, 166, 128, 31,
        98,  2,   207, 135,
    },
    {
        239, 50,  131, 164, 139, 51,  176, 32,  127, 16,  172, 253, 144, 24,
        47,  61,  97,  211, 129, 91,  56,  79,  157, 207, 243, 15,  191, 169,
        110, 64,  192, 189, 173, 44,  17,  2,   111, 71,  70,  41,  220, 249,
        130, 236, 170, 160, 174, 178, 34,  26,  62,  58,  104, 66,  76,  96,
        226, 67,  40,  52,  234, 156, 57,  229, 223, 137, 248, 187, 83,  63,
        8,   46,  119, 136, 68,  7,   103, 85,  150, 122, 98,  161, 43,  148,
        92,  72,  102, 222, 38,  3,   200, 22,  89,  212, 167, 244, 153, 115,
        198, 28,  230, 93,  215, 95,  142, 39,  242, 116, 18,  186, 210, 183,
        232, 208, 251, 196, 154, 105, 254, 138, 86,  233, 80,  100, 42,  225,
        134, 45,  117, 152, 25,  140, 88,  11,  113, 78,  55,  109, 246, 147,
        204, 112, 54,  255, 73,  205, 31,  101, 195, 33,  221, 219, 166, 182,
        217, 49,  206, 216, 120, 74,  159, 4,   1,   37,  179, 121, 9,   0,
        87,  81,  175, 203, 6,   146, 209, 185, 214, 171, 30,  59,  184, 247,
        194, 213, 5,   53,  224, 141, 84,  231, 162, 163, 90,  180, 190, 149,
        143, 60,  99,  132, 19,  155, 197, 29,  240, 10,  237, 126, 36,  106,
        12,  94,  151, 21,  65,  245, 13,  123, 69,  168, 199, 135, 114, 20,
        35,  165, 188, 252, 107, 218, 250, 77,  235, 158, 241, 193, 177, 108,
        181, 118, 82,  27,  227, 238, 23,  75,  128, 145, 133, 202, 201, 228,
        125, 14,  48,  124,
    },
    {
        121, 45,  134, 244, 145, 229, 172, 149, 50,  88,  173, 79,  84,  14,
        116, 78,  37,  255, 236, 155, 186, 215, 171, 102, 110, 233, 231, 106,
        188, 148, 93,  34,  222, 18,  123, 51,  217, 89,  159, 103, 25,  138,
        251, 174, 54,  6,   129, 13,  52,  26,  246, 80,  214, 33,  118, 115,
        27,  248, 135, 97,  12,  158, 65,  90,  105, 198, 71,  196, 240, 213,
        157, 235, 238, 96,  68,  205, 9,   252, 46,  197, 57,  61,  132, 113,
        141, 243, 163, 19,  177, 108, 38,  28,  207, 128, 239, 137, 176, 154,
        224, 7,   48,  91,  47,  99,  223, 36,  126, 11,  160, 95,  166, 107,
        228, 169, 66,  221, 76,  136, 184, 10,  206, 101, 39,  245, 2,   247,
        69,  58,  119, 131, 124, 70,  199, 250, 30,  253, 218, 182, 193, 190,
        56,  49,  201, 187, 43,  8,   195, 165, 73,  127, 21,  60,  202, 242,
        226, 194, 35,  140, 75,  175, 237, 146, 153, 183, 212, 16,  64,  98,
        104, 1,   40,  142, 63,  225, 100, 220, 3,   147, 133, 191, 139, 81,
        162, 59,  20,  112, 144, 168, 167, 210, 143, 53,  185, 109, 117, 32,
        83,  4,   125, 200, 254, 120, 29,  249, 22,  31,  230, 211, 150, 178,
        72,  77,  232, 156, 164, 122, 17,  170, 189, 44,  208, 15,  114, 23,
        241, 151, 111, 41,  42,  209, 24,  204, 179, 67,  180, 219, 161, 82,
        86,  74,  203, 216, 152, 87,  234, 130, 0,   92,  5,   62,  192, 55,
        85,  94,  181, 227,
    }};

std::vector<int> commutator = {
    112, 1,   2,   3,   4,   5,   6,   7,   8,   9,   10,  11,  12,  13,  14,
    15,  16,  17,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,
    30,  31,  32,  33,  34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,
    45,  46,  47,  48,  49,  50,  51,  52,  53,  54,  55,  56,  57,  58,  59,
    60,  61,  62,  63,  64,  65,  66,  67,  68,  69,  70,  71,  72,  73,  74,
    75,  76,  77,  78,  79,  80,  81,  82,  83,  84,  85,  86,  87,  88,  89,
    90,  91,  92,  93,  94,  95,  96,  97,  98,  99,  100, 101, 102, 103, 104,
    105, 106, 107, 108, 109, 110, 111, 0,   113, 114, 115, 116, 117, 118, 119,
    120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134,
    135, 136, 137, 138, 140, 139, 141, 142, 143, 144, 145, 146, 147, 148, 149,
    150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164,
    165, 166, 167, 168, 170, 169, 171, 172, 173, 174, 175, 176, 177, 178, 179,
    180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194,
    195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209,
    210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224,
    225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239,
    240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254,
    255,
};

int main() {
  Enigma e(reflector, rotors, commutator);

  auto s = binary::read_from_file();
  std::cout << "Read " << s.size() << " bytes\n";
  binary::write_to_file(e.encryptb(s));

  return 0;
}
