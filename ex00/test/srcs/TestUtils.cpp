#include "ScalarConverter.hpp"
#include "gtest/gtest.h"

// convertメソッドの標準出力の結果をstd::string型で返す
std::string getCapturedConvertStdout(std::string convertParam) {
  testing::internal::CaptureStdout();
  ScalarConverter::convert(convertParam);
  return testing::internal::GetCapturedStdout();
}

// convertメソッドの標準エラー出力の結果をstd::string型で返す
std::string getCapturedConvertStderr(std::string convertParam) {
  testing::internal::CaptureStderr();
  ScalarConverter::convert(convertParam);
  return testing::internal::GetCapturedStderr();
}

// convertメソッドの標準出力の結果(actual)がexpectと等しいかを調べる
void capturedConvertStdoutTest(std::string convertParam, std::string expect) {
  std::string actual = getCapturedConvertStdout(convertParam);
  EXPECT_EQ(expect, actual);
}

// convertメソッドの標準エラー出力の結果(actual)がexpectと等しいかを調べる
void capturedConvertStderrTest(std::string convertParam, std::string expect) {
  std::string actual = getCapturedConvertStderr(convertParam);
  EXPECT_EQ(expect, actual);
}
