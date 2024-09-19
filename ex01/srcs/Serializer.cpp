#include "Serializer.hpp"

Serializer::Serializer() {
  std::cout << "(constructor)Serializer Default constructor called"
            << std::endl;
}

Serializer::Serializer(const Serializer& other) {
  std::cout << "(constructor)Serializer Copy constructor called" << std::endl;
  *this = other;
}

Serializer& Serializer::operator=(const Serializer& other) {
  // because there is nothing attribute to assign
  if (this != &other) return *this;
  return *this;
}

Serializer::~Serializer() {
  std::cout << "(destructor)Serializer destructor called" << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr) {
  return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
  return reinterpret_cast<Data*>(raw);
}
