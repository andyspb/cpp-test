#include <iostream>
namespace dino_class {

class A {
 public:
  A()
      : i(0) {
    ::std::cout << __FUNCTION__ << std::endl;
  }
  static void ST_test() {
    ::std::cout << __FUNCTION__ << ::std::endl;
  }
  void test1() {
    ::std::cout << "A::test1()" << ::std::endl;
    i = 5;
  }
  void test2() {
    ::std::cout << "A::test2()" << ::std::endl;
    ++i;
  }
 private:
  int i;

};

void test() {
  ::std::cout << __FUNCTION__ << ::std::endl;
  A * a = NULL;

  A::ST_test();

  a->test1();
  //a->test2();

  A aa;
//        A& b = aa;

}
}
