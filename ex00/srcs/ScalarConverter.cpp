#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
  std::cout << "(constructor)ScalarConverter Default constructor called"
            << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
  std::cout << "(constructor)ScalarConverter Copy constructor called"
            << std::endl;
  *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
  // because there is nothing attribute to assign
  if (this != &other) return *this;
  return *this;
}

ScalarConverter::~ScalarConverter() {
  std::cout << "(destructor)ScalarConverter destructor called" << std::endl;
}

int ScalarConverter::convert(const std::string& input) {
  if (!input.empty())
    ;
  return EXIT_SUCCESS;
}
