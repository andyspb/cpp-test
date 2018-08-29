/*
 * 3_3_stack_with_min.h
 *
 *  Created on: 28 дек. 2014 г.
 *      Author: andy
 */

#ifndef _STACK_WITH_MIN_H_
#define _STACK_WITH_MIN_H_

#include <iostream>
#include <stack>

namespace stack_with_min {

/* A simple stack class with basic stack funtionalities */
class Stack {
 private:
  static const int max = 100;
  int arr[max];
  int top;
 public:
  Stack() {
    top = -1;
  }
  bool isEmpty() {
    return (top == -1);
  }

  bool isFull() {
    return (top == max - 1);
  }

  int pop() {
    if (isEmpty()) {
      std::cout << "Stack Underflow";
      abort();
    }
    int x = arr[top];
    top--;
    return x;
  }

  void push(int x) {
    if (isFull()) {
      std::cout << "Stack Overflow";
      abort();
    }
    top++;
    arr[top] = x;
  }

};

class StackWithMin : public Stack {
  Stack min;
 public:
  int pop();
  void push(int x);
  int getMin();
};

void StackWithMin::push(int x) {
  __SCOPE_LOG__;
  LOG(INFO) << " x=" << x << std::endl;
  if (isEmpty() == true) {
    Stack::push(x);
    min.push(x);
  } else {
    Stack::push(x);
    int y = min.pop();
    min.push(y);
    if (x < y)
      min.push(x);
    else
      min.push(y);
  }
}

int StackWithMin::pop() {
  __SCOPE_LOG__;
  int x = Stack::pop();
  min.pop();
  return x;
}

int StackWithMin::getMin() {
  __SCOPE_LOG__;
  int x = min.pop();
  std::cout << " x=" << x << std::endl;
  min.push(x);
  return x;
}

int test() {
  __SCOPE_LOG__;

  StackWithMin s;
  s.push(10);
  s.push(20);
  s.push(30);
  std::cout << s.getMin() << std::endl;
  s.push(5);
  std::cout << s.getMin() << std::endl;
  s.pop();
  std::cout << s.getMin() << std::endl;
  return 1;
}

}

#endif /* _STACK_WITH_MIN_H_ */
