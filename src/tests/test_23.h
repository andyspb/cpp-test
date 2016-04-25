/*
 * test_23.h
 *
 *  Created on: Apr 25, 2016
 *      Author: andy
 */

#ifndef SRC_TESTS_TEST_23_H_
#define SRC_TESTS_TEST_23_H_

namespace test_23 {

void swap(int& a, int& b) {
  int c = a;
  a = b;
  b = c;
}

void copy(int& a, const int& b) {
  a = b;
}

char* format_int_value_1(const char* format, int value) {
  char buffer[80];  // // warning: address of local variable ‘buffer’ returned
  sprintf(buffer, format, value);
  return buffer;
}
char* format_int_value_2(const char* format, int value) {
  static char buffer[80];
  sprintf(buffer, format, value);
  return buffer;
}
char* format_int_value_3(const char* format, int value) {
  char* buffer = new char[80];
  sprintf(buffer, format, value);
  return buffer;
}

struct A {
  A() {
    std::cout << "A()\n";
  }

  virtual ~A() {
    std::cout << "~A()\n";
  }
};

struct B : public A {
  B() {
    std::cout << "B()\n";
  }

  ~B() {
    std::cout << "~B()\n";
  }
};

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;
  int a = 1, b = 2;
  unsigned f = 5, g = 6;
  double w = 1.5, v = 3.1;

  swap(a, b);
//  swap(f, g); // invalid initialization of reference of type ‘int&’ from expression of type ‘unsigned int’

  copy(a, b);
  copy(a, g);

  g != f ? a : g = 9;
  g == f ? a : g = 9;

  g = a;
  g = f ? b : f;
  (f == 0 ? a : b) = 9;
//  (g == f ? a : g) = 9;  // : error: lvalue required as left operand of assignment

  A* ptrA = new B;
  delete ptrA;
  RETURN_OK();
}

}  // namespace test_23

#endif /* SRC_TESTS_TEST_23_H_ */
