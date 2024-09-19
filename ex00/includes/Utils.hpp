#ifndef UTILS_HPP
#define UTILS_HPP

#include <cctype>
#include <fstream>
#include <iostream>
#include <string>

#define ARGC_ERRMSG(MAKEFILE_PATH)                              \
  ("usage: ./" + getExecutableNameFromMakefile(MAKEFILE_PATH) + \
   " <literalToConvert>\n")

bool isFractionalPartZero(float f);
bool isFractionalPartZero(double d);
std::string getExecutableNameFromMakefile(const std::string& makefilePath);

#endif
