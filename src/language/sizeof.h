#ifndef _SIZEOF_H_
#define _SIZEOF_H_

namespace size_of {

#pragma pack(1)
class A {
 public:
  char c;
  long long l;
  int i;
};

class B {
 public:
  char c1;
  char c2;
  long long l;
};

struct S {
  int i;
  void *v;
  char c;
  long l;
};

struct Ref {
  Ref()
      : i(0),
        ref_i(i) {
  }
  int i;
  int& ref_i;
};

struct Date {
  int day :5;
  int month :4;
  int year;
};

int test() {
  std::cout << "sizeof(int)=" << sizeof(int) << std::endl;
  std::cout << "sizeof(Date)=" << sizeof(Date) << std::endl;

  //  std::cout << "sizeof(A)=" << sizeof(A) << std::endl;
//  std::cout << "sizeof(B)=" << sizeof(B) << std::endl;
//  std::cout << "sizeof(S)=" << sizeof(S) << std::endl;
//
//  char c = 1;
//  std::cout << "sizeof(c)=" << sizeof(c) << std::endl;
//
//  int i = 1;
//  std::cout << "sizeof(i)=" << sizeof(i) << std::endl;
//
//  float f = 1.0;
//  std::cout << "sizeof(f)=" << sizeof(f) << std::endl;
//
//  double d = 1.0;
//  std::cout << "sizeof(d)=" << sizeof(d) << std::endl;
//
//  int& ref_to_i = i;
//  std::cout << "sizeof(ref_to_i)=" << sizeof(ref_to_i)
//  << std::endl;
//
//  Ref ref;
//  std::cout << "sizeof(Ref)=" << sizeof(Ref) << std::endl;
//  std::cout << "sizeof(ref)=" << sizeof(ref) << std::endl;
  return 1;
}
}  // namespace size_of

#endif // _SIZEOF_H_
