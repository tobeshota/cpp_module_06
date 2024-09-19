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

int main(void) {
  Data* data = getData("username", 42, "VeryStrongPassword!");
  uintptr_t data_raw = Serializer::serialize(data);
  putData(data);
  std::cout << data_raw << std::endl;
  Data* deserializedData = Serializer::deserialize(data_raw);
  putData(deserializedData);
  delete data;
}

#ifdef DEBUG

__attribute__((destructor)) static void destructor() {
  system("leaks -q a.out");
}

#endif
