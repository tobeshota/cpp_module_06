#include "ScalarConverter.hpp"
#include "Utils.hpp"

int main(int argc, char **argv) {
  // return ScalarConverter::convert("inf");
  if (argc != 2) {
    std::cerr << ARGC_ERRMSG("./Makefile");
    return EXIT_FAILURE;
  }
  return ScalarConverter::convert(argv[1]);
}
