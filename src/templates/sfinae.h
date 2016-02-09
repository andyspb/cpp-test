/*
 * sfinae.h
 *
 *  Created on: Feb 9, 2016
 *      Author: andy
 */

#ifndef SRC_TEMPLATES_SFINAE_H_
#define SRC_TEMPLATES_SFINAE_H_

namespace sfinae {

template<class T>
struct is_pointer {
  template<class U>
  static char is_ptr(U *);

  template<class X, class Y>
  static char is_ptr(Y X::*);

  template<class U>
  static char is_ptr(U (*)());

  static double is_ptr(...);

  static T t;
  enum {
    value = sizeof(is_ptr(t)) == sizeof(char)
  };
};

struct Foo {
  int bar;
};

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;
  typedef int * IntPtr;
  typedef int Foo::* FooMemberPtr;
  typedef int (*FuncPtr)();

  printf("%d\n", is_pointer<IntPtr>::value);        // prints 1
  printf("%d\n", is_pointer<FooMemberPtr>::value);  // prints 1
  printf("%d\n", is_pointer<FuncPtr>::value);       // prints 1
  RETURN_OK();
}

}

#endif /* SRC_TEMPLATES_SFINAE_H_ */
