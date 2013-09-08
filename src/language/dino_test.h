#include <iostream>
namespace dino_class {

class A {
  public:
    A() {
      std::cout << __FUNCTION__ << std::endl;
    }
  private:
    int i;
  public:
    static void ST_test() {
      cout << __FUNCTION__ << endl;
    }
    void test1() {
      cout << "A::test1()" << endl;
      i = 5;
    }
    void test2() {
      cout << "A::test2()" << endl;
      i++;
    }

};

void test() {
  std::cout << __FUNCTION__ << std::endl;
  A * a = NULL;

  A::ST_test();

  a->test1();
  //a->test2();

  A aa;
//        A& b = aa;

}
}
