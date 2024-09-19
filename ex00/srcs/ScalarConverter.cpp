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

void ScalarConverter::putConvertedInput(t_convertedInput ci) {
  std::cout << "char: " << ci._asChar << std::endl;
  std::cout << "int: " << ci._asInt << std::endl;
  std::cout << "float: " << ci._asFloat << std::endl;
  std::cout << "double: " << ci._asDouble << std::endl;
}

static bool isDigitOrSign(char c) {
  return (isdigit(c) || c == '+' || c == '-');
}

bool ScalarConverter::isChar(const std::string& input) {
  return (input.length() == 3 && input[0] == '\'' && input[2] == '\'');
}

bool ScalarConverter::isInt(const std::string& input) {
  char* end;
  strtol(input.c_str(), &end, 10);
  return (*end == '\0');
}

bool ScalarConverter::isFloat(const std::string& input) {
  char* end;
  strtof(input.c_str(), &end);
  return (*end == 'f' && *(end + 1) == '\0');
}

bool ScalarConverter::isDouble(const std::string& input) {
  char* end;
  strtod(input.c_str(), &end);
  return (isDigitOrSign(input[0]) && *end == '\0');
}

/** pseudo literals
 * NaN: 値が数値でない[Not a Number]．0で割る操作などが該当する
 * inf: 値が無限大[Infinity]
 */
bool ScalarConverter::isPseudo(const std::string& input) {
  return (input == "nan" || input == "+inf" || input == "-inf" ||
          input == "nanf" || input == "+inff" || input == "-inff");
}

TYPE ScalarConverter::getInputTypeSafely(const std::string& input) {
  if (isPseudo(input))
    return PSEUDO;
  else if (isChar(input))
    return CHAR;
  else if (isInt(input))
    return INT;
  else if (isFloat(input))
    return FLOAT;
  else if (isDouble(input))
    return DOUBLE;
  throw std::invalid_argument(
      "error: <literalToConvert> type must be char or int or float or double");
  return INVALID;  // there is no possible to come here
}

std::string ScalarConverter::getAsChar(char c) {
  if (std::isnan(c))
    return "impossible";
  else if (std::isinf(c))
    return "overflow";
  else if (!std::isprint(c))
    return "Non displayable";
  return "'" + std::string(1, c) + "'";
}

std::string ScalarConverter::getAsInt(long l) {
  if (std::isnan(l)) return "impossible";
  if (std::isinf(l) || l > std::numeric_limits<int>::max() ||
      l < std::numeric_limits<int>::min())
    return "overflow";
  std::ostringstream oss;
  oss << l;
  return oss.str();
}

std::string ScalarConverter::getAsFloat(float f) {
  if (std::isinf(f))
    return (f > 0) ? "+inff" : "-inff";
  else if (std::isnan(f))
    return "nanf";
  std::ostringstream oss;
  if (isFractionalPartZero(f))
    oss << std::fixed << std::setprecision(1);  //  format with 1 decimal place
  oss << f;
  return oss.str() + "f";
}

std::string ScalarConverter::getAsDouble(double d) {
  if (std::isinf(d))
    return (d > 0) ? "+inf" : "-inf";
  else if (std::isnan(d))
    return "nan";
  std::ostringstream oss;
  if (isFractionalPartZero(d))
    oss << std::fixed << std::setprecision(1);  //  format with 1 decimal place
  oss << d;
  return oss.str();
}

// inputの型を文字列から実際の型に変換する（不当な値が入った場合の異常値の記述もここで行う）
t_convertedInput ScalarConverter::getConvertedInput(const std::string& input,
                                                    TYPE inputType) {
  t_convertedInput ci;
  char c = input[1];
  long l = strtol(input.c_str(), NULL, 10);
  float f = strtof(input.c_str(), NULL);
  double d = strtod(input.c_str(), NULL);
  switch (inputType) {
    case CHAR:
      ci._asChar = getAsChar(c);
      ci._asInt = getAsInt(static_cast<int>(c));
      ci._asFloat = getAsFloat(static_cast<float>(c));
      ci._asDouble = getAsDouble(static_cast<double>(c));
      break;
    case INT:
      ci._asChar = getAsChar(static_cast<char>(l));
      ci._asInt = getAsInt(l);
      ci._asFloat = getAsFloat(static_cast<float>(l));
      ci._asDouble = getAsDouble(static_cast<double>(l));
      break;
    case FLOAT:
      ci._asChar = getAsChar(static_cast<char>(f));
      ci._asInt = getAsInt(static_cast<char>(f));
      ci._asFloat = getAsFloat(f);
      ci._asDouble = getAsDouble(static_cast<double>(f));
      break;
    case DOUBLE:
      ci._asChar = getAsChar(static_cast<char>(d));
      ci._asInt = getAsInt(static_cast<char>(d));
      ci._asFloat = getAsFloat(d);
      ci._asDouble = getAsDouble(static_cast<double>(d));
      break;
    case PSEUDO:
      if (input == "nan" || input == "nanf") {
        ci._asChar = "impossible";
        ci._asInt = "impossible";
        ci._asFloat = getAsFloat(std::nanf(""));
        ci._asDouble = getAsDouble(std::nan(""));
      } else if (input == "+inf" || input == "+inff") {
        ci._asChar = "overflow";
        ci._asInt = "overflow";
        ci._asFloat = getAsFloat(std::numeric_limits<float>::infinity());
        ci._asDouble = getAsDouble(std::numeric_limits<double>::infinity());
      } else if (input == "-inf" || input == "-inff") {
        ci._asChar = "overflow";
        ci._asInt = "overflow";
        ci._asFloat = getAsFloat(-std::numeric_limits<float>::infinity());
        ci._asDouble = getAsDouble(-std::numeric_limits<double>::infinity());
      }
      break;
    case INVALID:
      throw std::invalid_argument(
          "error: <literalToConvert> type must be char or int or float or "
          "double");
  }
  return ci;
}

int ScalarConverter::convert(const std::string& input) {
  t_convertedInput ci;
  try {
    TYPE inputType = getInputTypeSafely(input);
    // inputの型を文字列から実際の型に変換する（ここではただ変換するだけ）
    ci = getConvertedInput(input, inputType);
    // 変換した値を出力する（不当な値が入った場合の異常値の記述もここで行う）
    putConvertedInput(ci);
  } catch (std::invalid_argument& e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
