#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>  //  for using uintptr_t in c++98

#include <iostream>

typedef struct s_data {
  std::string username;
  unsigned int age;
  std::string password;
} Data;

class Serializer {
 private:
  Serializer();
  Serializer(const Serializer& other);
  Serializer& operator=(const Serializer& other);
  ~Serializer();

 public:
  static uintptr_t serialize(Data* ptr);
  static Data* deserialize(uintptr_t raw);
};

#endif
