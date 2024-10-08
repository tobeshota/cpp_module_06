#include "ScalarConverter.hpp"
#include "Utils.hpp"

int main(int argc, char **argv) {
  if (argc != 2 || argv[1] == NULL) {
    std::cerr << ARGC_ERRMSG("./Makefile");
    return EXIT_FAILURE;
  }
  return ScalarConverter::convert(argv[1]);
}
