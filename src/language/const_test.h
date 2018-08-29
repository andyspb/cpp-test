#ifndef _CONST_H_
#define _CONST_H_

#include <iostream>
namespace const_ {
int strspcmp(const char * s1, const char * s2) {
//		char* pS1 = const_cast<char*>(s1);
//		char* pS2 = const_cast<char*>(s2);
  return 0;
}

int strspcmp1(char * s1, char * s2) {
//		const char* pS1 = s1;
//		const char* pS2 = s2;
  return 0;
}

class A {
 private:
  int x;
 public:
  A(int a) {
    x = a;
    std::cout << "A(int) // x=" << x << std::endl;
  }
  void f() {
    std::cout << "f() // x=" << x << std::endl;
  }
  void f() const {
    std::cout << "f() const // x=" << x << std::endl;
  }
  const int* const Method3(const int* const & i) const {
    std::cout << "Method const // x=" << x << std::endl;
    return i;
  }
};

const char * test1(char * ch) {
  return ch;
}

char test1(const char ch) {
  return ch;
}
const char test3(char ch) {
  return ch;
}

void test() {
  const int x = 0;             // x cannot be modified
  const int* pX = &x;      // pX is the address of a const int
  // and can't be used to change an int

//    *pX = 4;                 // illegal - can't use pX to change an int
  int* pInt;       // address of normal int
  pInt = const_cast<int*>(pX);
  const int x = 4;           // x is const, it can't be modified
  const int* pX = &x;        // you can't modify x through the pX pointer
  std::cout << x << std::endl;         // prints "4"
  int* pX2 = (int *) pX;      // explicitly cast pX as an int*
  *pX2 = 3;                  // result is undefined
  std::cout << x << std::endl;        // who knows what it prints?
  char * pCh_1;
  const char * pCh_2;

  char ch_1;
  const char ch_2 = '2';

//		char * const pCh_3 = &ch_1;
  pCh_1 = &ch_1;
  pCh_2 = &ch_2;
//		const char * const pCh_4 = &ch_2;

  char * pCh_5;
  pCh_5 = &ch_1;

  A a1(1);
  a1.f();
  A const a2(2);
  a2.f();
  int ii = 0;
  a1.Method3(&ii);
  a2.Method3(&ii);

  int someOtherIntVar = 0;
//		const int constSomeOtherIntVar = 0;
//		const int x = 0;      // constant int
//		x = 2;            // illegal - can't modify x
  const int* pX;    // changeable pointer to constant int
//		*pX = 3;          // illegal -  can't use pX to modify an int
  pX = &someOtherIntVar;      // legal - pX can point somewhere else
  int* const pY = &someOtherIntVar;        // constant pointer to changeable int
  *pY = 4;                    // legal - can use pY to modify an int
  //pY = &someOtherIntVar;      // illegal - can't make pY point anywhere else
//		const int* const pZ= &constSomeOtherIntVar;        // const pointer to const int
//		*pZ = 5;                    // illegal - can't use pZ to modify an int
//		pZ = &someOtherIntVar;      // illegal - can't make pZ point anywhere else
  int y = 0;
//		const int* pConstY = &y;  // legal - but can't use pConstY to modify y
  int* pMutableY = &y;      // legal - can use pMutableY to modify y
  *pMutableY = 42;
  return;
}
}  // namespace const_

#endif // _CONST_H_
