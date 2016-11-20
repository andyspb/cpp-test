//  test5.h
//  author: andrey.krutogolov@gmail.com
//  date:   14.03.2013
//  тест

#ifndef TESTS5_H_
#define TESTS5_H_

#include <iostream>
using namespace std;

namespace test_5 {

class Base {
 public:
  Base() {
    cout << "from Base()\n";
  }

  virtual ~Base() {
    cout << "from ~Base()\n";
  }

};

class T : public Base{
 public:
  T()
      : v(0) {
    cout << "T::T()\n";
  }
  virtual ~T() {
    cout << "T::~T()\n";
  }

  T(const T& t) {
    cout << "T::T(const T& t)\n";
    clone(t);
  }

  T& operator=(const T& x) {
    cout << "T::operator=(const T& t)\n";
    if (this != &x) {
      this->T::~T();
      cout << "calling new (this) T(x);\n";
      new (this) T(x);
      cout << "after new (this) T(x);\n";
    }
    return *this;
  }

 private:
  void clone(const T& t) {
    // clone
    v = t.v;
  }
  int v;
};

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;

  T t1, t2;

  t2 = t1;
  RETURN_OK();
}

}  // namespace test_5

#endif  // TESTS5_H_
