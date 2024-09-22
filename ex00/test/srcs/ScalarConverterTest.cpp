#include "TestUtils.cpp"

// printable
TEST(CharInputTest, CharPrintableTest) {
  capturedConvertStdoutTest("\'4\'", "char: '4'\nint: 52\nfloat: 52.0f\ndouble: 52.0\n");
  capturedConvertStdoutTest("\'2\'", "char: '2'\nint: 50\nfloat: 50.0f\ndouble: 50.0\n");
  capturedConvertStdoutTest("\' \'", "char: ' '\nint: 32\nfloat: 32.0f\ndouble: 32.0\n");
  capturedConvertStdoutTest("\'T\'", "char: 'T'\nint: 84\nfloat: 84.0f\ndouble: 84.0\n");
  capturedConvertStdoutTest("\'O\'", "char: 'O'\nint: 79\nfloat: 79.0f\ndouble: 79.0\n");
  capturedConvertStdoutTest("\'k\'", "char: 'k'\nint: 107\nfloat: 107.0f\ndouble: 107.0\n");
  capturedConvertStdoutTest("\'y\'", "char: 'y'\nint: 121\nfloat: 121.0f\ndouble: 121.0\n");
  capturedConvertStdoutTest("\'o\'", "char: 'o'\nint: 111\nfloat: 111.0f\ndouble: 111.0\n");
  capturedConvertStdoutTest("\'!\'", "char: '!'\nint: 33\nfloat: 33.0f\ndouble: 33.0\n");
}

// unprintable
TEST(CharInputTest, CharUnprintableTest) {
  capturedConvertStdoutTest("", "char: Non displayable\nint: 0\nfloat: 0.0f\ndouble: 0.0\n");
  capturedConvertStdoutTest("0", "char: Non displayable\nint: 0\nfloat: 0.0f\ndouble: 0.0\n");
  capturedConvertStdoutTest("31", "char: Non displayable\nint: 31\nfloat: 31.0f\ndouble: 31.0\n");
  capturedConvertStdoutTest("127", "char: Non displayable\nint: 127\nfloat: 127.0f\ndouble: 127.0\n");
}

// Decimal number
TEST(FloatInputTest, DecimalNumberTest) {
  std::string coinTossLandingOnHeads = "0.51";

  capturedConvertStdoutTest("0.0f", "char: Non displayable\nint: 0\nfloat: 0.0f\ndouble: 0.0\n");
  capturedConvertStdoutTest("42.195", "char: '*'\nint: 42\nfloat: 42.195f\ndouble: 42.195\n");
  capturedConvertStdoutTest(coinTossLandingOnHeads, "char: Non displayable\nint: 0\nfloat: 0.51f\ndouble: 0.51\n");
}


// Overflow
TEST(IntInputTest, IntUnprintableTest) {
  // 2147483648 == INT_MAX(2147483647) + 1
  capturedConvertStdoutTest("2147483648", "char: Non displayable\nint: overflow\nfloat: 2.14748e+09f\ndouble: 2.14748e+09\n");
  // -2147483649 == INT_MIN(-2147483648) - 1
  capturedConvertStdoutTest("-2147483649", "char: Non displayable\nint: overflow\nfloat: -2147483648.0f\ndouble: -2.14748e+09\n");
}

// NaN: Not a Number
TEST(PseudoInputTest, NaNTest) {
  capturedConvertStdoutTest("nan", "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n");
  capturedConvertStdoutTest("nanf", "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n");
}

// Inf: Infinity
TEST(PseudoInputTest, PlusInfTest) {
  capturedConvertStdoutTest("+inf", "char: overflow\nint: overflow\nfloat: +inff\ndouble: +inf\n");
  capturedConvertStdoutTest("+inff", "char: overflow\nint: overflow\nfloat: +inff\ndouble: +inf\n");
}

// Inf: Infinity
TEST(PseudoInputTest, MinusInfTest) {
  capturedConvertStdoutTest("-inf", "char: overflow\nint: overflow\nfloat: -inff\ndouble: -inf\n");
  capturedConvertStdoutTest("-inff", "char: overflow\nint: overflow\nfloat: -inff\ndouble: -inf\n");
}

// invalid
TEST(InvalidInputTest, InvalidInputTest) {
  capturedConvertStderrTest("hoge", "error: <literalToConvert> type must be char or int or float or double\n");
  capturedConvertStderrTest("fuga", "error: <literalToConvert> type must be char or int or float or double\n");
  capturedConvertStderrTest("piyo", "error: <literalToConvert> type must be char or int or float or double\n");
  capturedConvertStderrTest("inf", "error: <literalToConvert> type must be char or int or float or double\n");
}
