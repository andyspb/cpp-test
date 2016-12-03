#ifndef _TEMPLATE_TEST1_H_
#define _TEMPLATE_TEST1_H_

#include <iostream>
#include <typeinfo>

namespace template_test1 {
template<class T>
class TemplateTest {
 public:
  void print() {
    std::cout << "this is from pure template\n";
//            cout<<"t="<<t<<endl;
  }
 protected:
  T t;
};

template<>
class TemplateTest<char> {
 public:
  void print() {
    std::cout << "this is from <char> template\n";
    std::cout << "t=" << t << std::endl;
  }
 protected:
  char t;
};

template<class T = int> class X {
};
X<> a;
//X b;

int test() {
  printf("template class test\n");
  TemplateTest<std::string> test;
  std::cout << "type of test= " << typeid(test).name() << std::endl;
  test.print();
  TemplateTest<char> ch;
  std::cout << "type of ch= " << typeid(ch).name() << std::endl;
  ch.print();
  return 1;
}
}  // namespace template_test1

#endif  // _TEMPLATE_TEST1_H_
