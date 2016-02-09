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
  void add(unique_ptr<B>& b) {
    vb.push_back(move(b));
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
  LOG(INFO) << __PRETTY_FUNCTION__;

  unique_ptr<T const> p1(bar());        // OK
  unique_ptr<T const[]> a1(bar());        // OK

  unique_ptr<T const> p2(foo());        // OK
  unique_ptr<T const[]> a2(foo());        // ? this is line #15
  A a;
  unique_ptr<B> b(new B());
  a.add(b);

  RETURN_OK();
}

}  // namespace atomic_

#endif /* SRC_LANGUAGE_ATOMIC_H_ */
