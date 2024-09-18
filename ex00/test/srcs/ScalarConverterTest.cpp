#include "ScalarConverter.hpp"
#include "gtest/gtest.h"

TEST(ConvertTest, CharTest) {
  testing::internal::CaptureStdout();
  ScalarConverter::convert("c");
  const std::string actual = testing::internal::GetCapturedStdout();
  const std::string expect =
      "char: c\nint: 99\nfloat: 99.000000\ndoule: 99.000000\n";
  EXPECT_EQ(expect, actual);
}
