/*
 * so_1.h
 *
 *  Created on: Jul 21, 2015
 *      Author: andy
 */

#ifndef SRC_STACKOVERFLOW_SO_1_H_
#define SRC_STACKOVERFLOW_SO_1_H_

#include <memory>

// http://stackoverflow.com/questions/31541008/dependent-types-template-argument-deduction-failed

namespace so_1 {

template<typename T>
struct Image {
  typedef ::std::shared_ptr<Image<T>> Ptr;
};

template<typename T>
void function1(typename Image<T>::Ptr v) {
}

template<typename T>
void function2(::std::shared_ptr<Image<T>> v) {
}

int test(void) {
  LOG(INFO) << __PRETTY_FUNCTION__;
  Image<int>::Ptr test = ::std::make_shared<Image<int>>();
//  function1(test);       // Does NOT compile
//  function1<int>(test);  // Does compile
//  function2(test);       // Does compile
  return 1;
}

}

#endif /* SRC_STACKOVERFLOW_SO_1_H_ */
