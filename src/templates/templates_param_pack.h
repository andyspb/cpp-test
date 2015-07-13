/*
 * templates_param_pack.h
 *
 *  Created on: Jul 13, 2015
 *      Author: andy
 */

#ifndef SRC_TEMPLATES_TEMPLATES_PARAM_PACK_H_
#define SRC_TEMPLATES_TEMPLATES_PARAM_PACK_H_

namespace templates_param_pack {

template<typename ... U> void g() {
}

template<class ... Types> struct Tuple {
};
Tuple<> t0;           // Types contains no arguments
Tuple<int> t1;        // Types contains one argument: int
Tuple<int, float> t2;  // Types contains two arguments: int and float
Tuple<float, float> error;       // error: 0 is not a type

//template<class ...Us> void f(Us ... pargs) {
//  LOG(INFO) << __PRETTY_FUNCTION__;
//  std::cout << "f templ" << std::endl;
//}

template<class U1, class U2, class U3>
void f(U1 u1, U2 u2, U3 u3) {
  LOG(INFO) << __PRETTY_FUNCTION__;
  std::cout << *u1 << std::endl;
  std::cout << *u2 << std::endl;
  std::cout << *u3 << std::endl;
}

template<int*, class U2, class U3>
void f(int* u1, U2 u2, U3 u3) {
  LOG(INFO) << __PRETTY_FUNCTION__;
  LOG(INFO) << "f int";
  std::cout << *u1 << std::endl;
  std::cout << *u2 << std::endl;
  std::cout << *u3 << std::endl;
}

template<class ...Ts> void g(Ts ... args) {
  f(&args...);  // &args... is a pack expansion
                // &args is its pattern
}

int test() {
  LOG(INFO) << __PRETTY_FUNCTION__;
  g(1, 0.2, "a");

  LOG(INFO) << "<<<";
  return 1;
}

}  // namespace templates_param_pack

#endif /* SRC_TEMPLATES_TEMPLATES_PARAM_PACK_H_ */
