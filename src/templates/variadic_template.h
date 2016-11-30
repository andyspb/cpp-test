/*
 * variadic_template.h
 *
 *  Created on: 14 ����. 2016 �.
 *      Author: andy
 */

#ifndef SRC_TEMPLATES_VARIADIC_TEMPLATE_H_
#define SRC_TEMPLATES_VARIADIC_TEMPLATE_H_

namespace variadic_template {

template<class ... > struct Tuple {

};
Tuple<> t0;           // Types contains no arguments
Tuple<int> t1;        // Types contains one argument: int
Tuple<int, float> t2; // Types contains two arguments: int and float
//Tuple<0> error;       // error: 0 is not a type

template<typename ... Types> void f(Types ... args) {
  LOG(INFO) << "From: template<class ... Types> void f()";
  const unsigned numargs = sizeof...(args);
  const int size = sizeof...(args) + 2;

  LOG(INFO) << "numargs=" << numargs
      << ", size=" << size;

  std::initializer_list<double> res = {1,args...,-1};

  //LOG(INFO) << "res[1]=" << res.[1] << ", res[2]=" << res[2];

  int dummy[sizeof...(Types)] = {
      (LOG(INFO) << args << " ", 0)...
  };

}

template<typename T1, typename T2> void f(T1 i, T2 d) {
  LOG(INFO) << "template<int, int> void f(int i, int d)";
  LOG(INFO) << "i=" << i << ", d=" << d;
}

template<> void f() {
  LOG(INFO) << "From: template<> void f()";
}

//template<typename T> void f(T i) {
//  LOG(INFO) << "From: template<typename T> void f(int i) i:" << i;
//}

template<typename ... Types>
class VariadicTemplate
{
};


template<typename U, typename... Ts> struct Invalid; // Ts.. not at the end
template<typename... Ts, typename U> void invalid(); // U not deduced

TEST_RESULT test() {
  __SCOPE_LOG__;

  f();       // OK: args contains no arguments
  f<int>(1);      // OK: args contains one argument: int
  f<int, double>(2, 1.5); // OK: args contains two arguments: int and double
  f<int, int>(5, 6); // OK: args contains two arguments: int and double


  RETURN_OK();
}

}  // variadic_template

#endif /* SRC_TEMPLATES_VARIADIC_TEMPLATE_H_ */
