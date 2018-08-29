/*
 * 3_5_impl_que_with_two_stacks.h
 *
 *  Created on: 30 дек. 2014 г.
 *      Author: andy
 */

#ifndef _IMPL_QUE_WITH_TWO_STACKS_H_
#define _IMPL_QUE_WITH_TWO_STACKS_H_

// Implement a MyQueue class which implements a queue using two stacks.

#include <stack>

namespace que_from_2stacks {

template<typename T>
class Myque {
 public:
  Myque() {
  }
  int size() const {
    return stackNewest.size() + stackOldest.size();
  }
  void add(T value) {
    stackNewest.push(value);
  }

  T top() {
    shiftStacks();
    return stackOldest.top();
  }

  T pop() {
    shiftStacks();
    return stackOldest.pop();
  }
 private:
  void shiftStacks() {
    if (stackOldest.isEmpty()) {
      while (!stackNewest.isEmpty()) {
        stackOldest.push(stackNewest.pop());
      }
    }
  }

  std::stack<T> stackNewest, stackOldest;

};

}  // que_from_2stacks

#endif /* _IMPL_QUE_WITH_TWO_STACKS_H_ */
