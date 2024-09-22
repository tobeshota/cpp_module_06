#include <gtest/gtest.h>

#include "Identify.hpp"

std::string getCapturedIdentifyStdout(Base* p) {
  testing::internal::CaptureStdout();
  identify(p);
  return testing::internal::GetCapturedStdout();
}

std::string getCapturedIdentifyStdout(Base& p) {
  testing::internal::CaptureStdout();
  identify(p);
  return testing::internal::GetCapturedStdout();
}

void capturedIdentifyStdoutTest(Base* newed_p, std::string expect) {
  std::string actual = getCapturedIdentifyStdout(newed_p);
  EXPECT_EQ(actual, expect);
  delete newed_p;
}

void capturedIdentifyStdoutTest(Base& newed_p, std::string expect) {
  std::string actual = getCapturedIdentifyStdout(newed_p);
  EXPECT_EQ(actual, expect);
  delete &newed_p;
}
