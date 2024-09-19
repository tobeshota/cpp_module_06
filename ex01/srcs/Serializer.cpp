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

/**reinterpret_cast 演算子
 * @brief
 * ポインターが他のポインター型に変換されることを許可します．
 * また，整数型から任意のポインター型への変換およびその逆の変換を許可します．
 * @cite
 * https://learn.microsoft.com/ja-jp/cpp/cpp/reinterpret-cast-operator?view=msvc-170
 */
uintptr_t Serializer::serialize(Data* ptr) {
  return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
  return reinterpret_cast<Data*>(raw);
}
