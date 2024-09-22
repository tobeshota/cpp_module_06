#include "TestUtils.cpp"

// generate関数がランダムにAかBかCを出す
TEST(IdentifyTest, generateTest) {
  Base* typeAorBorC = generate();
  bool isTypeA = (dynamic_cast<A*>(typeAorBorC) != NULL);
  bool isTypeB = (dynamic_cast<B*>(typeAorBorC) != NULL);
  bool isTypeC = (dynamic_cast<C*>(typeAorBorC) != NULL);
  EXPECT_TRUE(isTypeA || isTypeB || isTypeC);
}

// Base *pの実際の型を出力するidentify関数が存在する
TEST(IdentifyTest, IdentifyActualTypeOfPointer) {
  capturedIdentifyStdoutTest(new A(), "A\n");
  capturedIdentifyStdoutTest(new B(), "B\n");
  capturedIdentifyStdoutTest(new C(), "C\n");
  capturedIdentifyStdoutTest(new Base(), "Object type is not A or B or C\n");
}

// Base &pの実際の型を出力するidentify関数が存在する
TEST(IdentifyTest, IdentifyActualTypeOfReference) {
  A& aRef = *(new A());
  B& bRef = *(new B());
  C& cRef = *(new C());
  Base& baseRef = *(new Base());
  capturedIdentifyStdoutTest(aRef, "A\n");
  capturedIdentifyStdoutTest(bRef, "B\n");
  capturedIdentifyStdoutTest(cRef, "C\n");
  capturedIdentifyStdoutTest(baseRef, "Object type is not A or B or C\n");
}
