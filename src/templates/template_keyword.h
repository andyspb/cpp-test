#ifndef _TEMPLATE_KEYWORD_H_
#define _TEMPLATE_KEYWORD_H_

#include <iostream>

namespace template_keyword {

class X {
  public:
    template<int j>
    struct S {
        void h() {
          std::cout << "member template's member function: " << j << std::endl;
        }
    };
    template<int i>
    void f() {
      std::cout << "Primary: " << i << std::endl;
    }
};

template<>
void X::f<20>() {
  std::cout << "Specialized, non-type argument = 20" << std::endl;
}

template<class T>
void g(T* p) {
  p->template f<100>();
  p->template f<20>();
  typename T::template S<40> s;  // use of scope operator on a member template
  s.h();
}

int test() {
  std::cout << "Test: template keyword --->" << std::endl;
  X temp;
  g(&temp);
  return 1;
}
}  // namespace

#endif // _TEMPLATE_KEYWORD_H_
