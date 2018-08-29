/*
 * type_traits.h
 *
 *  Created on: Sep 3, 2015
 *      Author: andy
 */

#ifndef SRC_LANGUAGE_TYPE_TRAITS_H_
#define SRC_LANGUAGE_TYPE_TRAITS_H_

#include <type_traits>
#include <iostream>

namespace type_traits {

template<typename T>
struct Wrapper {
  Wrapper()
      : p_(0) {
    std::cout << "is_void<T>:" << std::is_void<T>::value << '\n';
    std::cout << "is_pod<T>:" << std::is_pod<T>::value << '\n';
  }
  ;
  T* p_;
};

typedef void T_void;
typedef int T_int;

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;

  constexpr void* p = NULL;
  constexpr int n = 1;

  std::cout << std::boolalpha;
  Wrapper<void> w1;
  Wrapper<int> w2;
  std::cout << std::is_void<T_void>::value << '\n';
  std::cout << std::is_void<void>::value << '\n';
  std::cout << std::is_void<int>::value << '\n';
  std::cout << std::is_integral<T_int>::value << '\n';

  RETURN_OK();
}

}  // namespace type_traits

#endif /* SRC_LANGUAGE_TYPE_TRAITS_H_ */
