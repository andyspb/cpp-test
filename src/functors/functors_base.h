//  functors.h
//  author: andrey.krutogolov@gmail.com
//  date:   08.03.2013

#ifndef FUNCTORS_H_
#define FUNCTORS_H_

#include <iostream>

namespace functors_base {

class BaseFunctor {
 public:
  virtual ~BaseFunctor() = 0;
  // two possible functions to call member function. virtual cause derived
  // classes will use a pointer to an object and a pointer to a member function
  // to make the function call
  virtual void operator()(const char* string)=0;  // call using operator
  virtual void Call(const char* string)=0;        // call using function
};

BaseFunctor::~BaseFunctor() {
}

// derived template class
template<class T> class SpecificFunctor : public BaseFunctor {
 private:
  void (T::*fpt)(const char*);   // pointer to member function
  T* pt2Object;                  // pointer to object

 public:
  SpecificFunctor(T* _pt2Object, void (T::*_fpt)(const char*)) {
    pt2Object = _pt2Object;
    fpt = _fpt;
    LOG(INFO) << __PRETTY_FUNCTION__ << "pt2Object:" << pt2Object;
  }

  virtual ~SpecificFunctor() {
    LOG(INFO) << __PRETTY_FUNCTION__ << " pt2Object:" << pt2Object;
    if (pt2Object) {
//      delete pt2Object;
    }
  }
  virtual void operator()(const char* string) {
    LOG(INFO) << __PRETTY_FUNCTION__;
    (*pt2Object.*fpt)(string);
  }

  virtual void Call(const char* string) {
    LOG(INFO) << __PRETTY_FUNCTION__;
    (*pt2Object.*fpt)(string);
  }
};

class A {
 public:
  A() {
    __SCOPE_LOG__;
  }

  void Display(const char* text) {
    __SCOPE_LOG__;
    std::cout << text << std::endl;
  }
};

class B {
 public:

  B() {
  }

  void Display(const char* text) {
    std::cout << text << std::endl;
  }
};

int x = 1;
int y = 2;
const int s = 3;

TEST_RESULT test() {
  __SCOPE_LOG__;
  A a;
  B b;

  SpecificFunctor<A> specFuncA(&a, &A::Display);
  SpecificFunctor<B> specFuncB(&b, &B::Display);

  BaseFunctor* vTable[] = { &specFuncA, &specFuncB };

  vTable[0]->Call("A::Display called!");        // via function "Call"
  (*vTable[1])("B::Display called!");        // via operator "()"

#ifdef __linux__
#pragma GCC diagnostic ignored "-Wuninitialized"
#elif _WIN32
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#endif

  int x = ::functors_base::x;
  int y = ::functors_base::y;

  int arr[s];

  std::cout << "x: " << x << std::endl;
  std::cout << "y: " << y << std::endl;
  std::cout << "sizeof(arr): " << sizeof(arr) / sizeof(arr[0]) << std::endl;
  std::cout << "sizeof(string literal): " << sizeof("a") << std::endl;
  RETURN_OK();
}

}  // namespace functors

#endif  // FUNCTORS_H_
