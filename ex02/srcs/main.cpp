#include "Identify.hpp"

int main(void) {
  Base* typeAorBorC = generate();
  Base& ref = *typeAorBorC;
  identify(typeAorBorC);
  identify(ref);
  delete typeAorBorC;
}
