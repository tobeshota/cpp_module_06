#include <gtest/gtest.h>

#include "Serializer.hpp"

static Data* getData(std::string username, unsigned int age,
                     std::string password) {
  Data* data = new Data;
  data->username = username;
  data->age = age;
  data->password = password;
  return data;
}

static void putData(Data* data) {
  std::cout << data->username << std::endl;
  std::cout << data->age << std::endl;
  std::cout << data->password << std::endl;
}

std::string getCapturedConvertStdout(Data* data) {
  testing::internal::CaptureStdout();
  putData(data);
  return testing::internal::GetCapturedStdout();
}
