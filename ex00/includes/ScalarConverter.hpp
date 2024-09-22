#ifndef SCHALAR_CONVERTER_HPP
#define SCHALAR_CONVERTER_HPP

#include <cmath>
#include <cstdlib>  // for std::strtol, std::strtof, std::strtod
#include <iomanip>  // for std::fixed and std::setprecision
#include <iostream>
#include <limits>  // for detect overflow or special value
#include <sstream>

#include "Utils.hpp"

enum TYPE { PSEUDO, CHAR, INT, FLOAT, DOUBLE, INVALID };

typedef struct s_convertedInput {
  std::string _asChar;
  std::string _asInt;
  std::string _asFloat;
  std::string _asDouble;
} t_convertedInput;

class ScalarConverter {
 public:
  static int convert(const std::string& input);

 private:
  /* * * canonical form * * */
  ScalarConverter();  // Constructor private to prevent instantiation
  ScalarConverter(const ScalarConverter& other);
  ScalarConverter& operator=(const ScalarConverter& other);
  ~ScalarConverter();

  /* * * method * * */
  // get input type
  static bool isChar(const std::string& input);
  static bool isInt(const std::string& input);
  static bool isFloat(const std::string& input);
  static bool isDouble(const std::string& input);
  static bool isPseudo(const std::string& input);
  static TYPE getInputTypeSafely(const std::string& input);
  // converted input
  static t_convertedInput getConvertedInput(const std::string& input,
                                            TYPE inputType);
  static std::string getAsChar(char c);
  static std::string getAsInt(long l);
  static std::string getAsFloat(float f);
  static std::string getAsDouble(double d);
  // put converted input
  static void putConvertedInput(t_convertedInput ci);
};

#endif
