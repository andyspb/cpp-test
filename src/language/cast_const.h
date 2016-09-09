/*
 * cast_const.h
 *
 *  Created on: Jul 13, 2015
 *      Author: andy
 */

#ifndef SRC_LANGUAGE_CAST_CONST_H_
#define SRC_LANGUAGE_CAST_CONST_H_

namespace cast_const {

struct Base {
  Base() {
    value_ = 0;
  }

  int getValue() {
    return value_;
  }

  void incValue() {
    ++value_;
  }

//  int getValue() const {
//    const_cast<Base*>(this))->incValue();
//    return const_cast<Base*>(this))->value;
//  }

  void setValue(int value) const {
          // this->i = v;                 // compile error: this is a pointer to const
    const_cast<Base*>(this)->value_ = value; // OK as long as the type object isn't const
  }

  void setValue(int value){
    value_ = value; // OK
  }

  int value_;

};


TEST_RESULT test() {
  __SCOPE_LOG__;

//  int* x = (const int*)malloc(10);  // illegal
  const int* x = (const int*)malloc(10);  // legal
  delete(x);

  int i = 3;                    // i is not declared const
  const int& cref_i = i;
  const_cast<int&>(cref_i) = 4; // OK: modifies i
  std::cout << "i = " << i << '\n';

  Base b; // note, if this is const type t;, then t.m1(4); is UB
  b.setValue(4);
  std::cout << "type::i = " << b.value_ << '\n';

  const int j = 3; // j is declared const
  int* pj = const_cast<int*>(&j);
  *pj = 4;
  std::cout << "*pj = " << *pj << '\n';

  return TEST_OK;
}

}  // namespace cast_const

#endif /* SRC_LANGUAGE_CAST_CONST_H_ */
