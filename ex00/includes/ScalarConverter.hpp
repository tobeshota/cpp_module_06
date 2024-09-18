#ifndef SCHALAR_CONVERTER_HPP
#define SCHALAR_CONVERTER_HPP

#include <cstdlib>  // for std::strtol, std::strtof, std::strtod
#include <iostream>
#include <limits>  // for detect overflow or special value

class ScalarConverter {
 private:
  ScalarConverter();  // Constructor private to prevent instantiation
 public:
  static int convert(const std::string& input);
};

#endif
