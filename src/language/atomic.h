/*
 * atomic.h
 *
 *  Created on: Aug 31, 2015
 *      Author: andy
 */

#ifndef SRC_LANGUAGE_ATOMIC_H_
#define SRC_LANGUAGE_ATOMIC_H_

namespace atomic_ {

class B { /* */
};

class A {
  std::vector<std::unique_ptr<B>> vb;
 public:
  void add(std::unique_ptr<B>& b) {
    vb.push_back(std::move(b));
  }
};

struct T {
};

T* foo() {
  return new T;
}
T const* bar() {
  return foo();
}

TEST_RESULT test() {
  __SCOPE_LOG__;

  std::unique_ptr<T const> p1(bar());        // OK
  std::unique_ptr<T const[]> a1(bar());        // OK

  std::unique_ptr<T const> p2(foo());        // OK
  std::unique_ptr<T const[]> a2(foo());        // ? this is line #15
  A a;
  std::unique_ptr<B> b(new B());
  a.add(b);

  RETURN_OK();
}

}  // namespace atomic_

#endif /* SRC_LANGUAGE_ATOMIC_H_ */
