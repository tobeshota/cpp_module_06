#include "Identify.hpp"

typedef enum { typeA, typeB, typeC } typeABC;

static typeABC randomABC(void) {
  std::srand(std::time(0));
  return (typeABC)(std::rand() % 3);
}

/**
 * It randomly instanciates A, B or C and returns the instance as a Base
 * pointer. Feel free to use anything you like for the random choice
 * implementation.
 */

/**dynamic_cast 演算子
 * @brief
 * オペランド expression を type-id 型のオブジェクトに変換する
 * なお，クラスの階層構造で特定のクラスから下位に
 * (つまり、そのクラスから派生したクラスに)
 * ポインターを移動することをダウンキャストと呼ぶ．
 * @cite
 * https://learn.microsoft.com/ja-jp/cpp/cpp/dynamic-cast-operator?view=msvc-170
 */
Base* generate(void) {
  // ランダムにAかBかCを決める
  switch (randomABC()) {
    case typeA:
      return new A();
    case typeB:
      return new B();
    case typeC:
      return new C();
  }
  // don't come here
  return NULL;
}

/**
 * It prints the actual type of the object pointed to by p: "A", "B" or "C".
 * ポインタを使ったdynamic_cast では，キャストに失敗した際にnullptrが返される．
 */
void identify(Base* p) {
  if (dynamic_cast<A*>(p))
    std::cout << OBJECT_TYPE_IS_A_MSG << std::endl;
  else if (dynamic_cast<B*>(p))
    std::cout << OBJECT_TYPE_IS_B_MSG << std::endl;
  else if (dynamic_cast<C*>(p))
    std::cout << OBJECT_TYPE_IS_C_MSG << std::endl;
  else
    std::cout << UNKNOWN_OBJECT_MSG << std::endl;
}

/**
 * It prints the actual type of the object pointed to by p: "A", "B" or "C".
 * Using a pointer inside this function is forbidden.
 * 参照を使ったdynamic_cast では，キャストに失敗した際に例外が飛ぶ．
 */
void identify(Base& p) {
  try {
    (void)dynamic_cast<A&>(p);
    std::cout << OBJECT_TYPE_IS_A_MSG << std::endl;
  } catch (const std::bad_cast& e) {
    try {
      (void)dynamic_cast<B&>(p);
      std::cout << OBJECT_TYPE_IS_B_MSG << std::endl;
    } catch (const std::bad_cast& e) {
      try {
        (void)dynamic_cast<C&>(p);
        std::cout << OBJECT_TYPE_IS_C_MSG << std::endl;
      } catch (const std::bad_cast& e) {
        std::cout << UNKNOWN_OBJECT_MSG << std::endl;
      }
    }
  }
}
