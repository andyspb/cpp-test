/*
 * 3_6_sort_stack_ascending.h
 *
 *  Created on: 30 дек. 2014 г.
 *      Author: andy
 */

#ifndef _SORT_STACK_ASCENDING_H_
#define _SORT_STACK_ASCENDING_H_

#include <stack>
#include <iostream>

//Write a program to sort a stack in ascending order (with biggest items on top).
//You may use at most one additional stack to hold items, but you may not copy the
//elements into any other data structure (such as an array). The stack supports the
//following operations: push, pop, peek, and isEmpty

namespace sort_stack_ascending {

void print_stack(std::stack<int> stack) {
  while (!stack.empty()) {
    int v;
    v = stack.top();
    stack.pop();
    std::cout << v << " ";
  }
  std::cout << std::endl;
}

void sort_stack_with_2add_stacks(std::stack<int> &s) {
  int v0, v1, min;
  std::stack<int> temp_stack1, temp_stack2;
  v0 = s.top();
  s.pop();
  if (s.empty()) {  // do not need sort if one element
    s.push(v0);
    return;
  }

  s.push(v0);

  while (!s.empty()) {
    v0 = s.top();
    s.pop();
    temp_stack1.push(v0);
  }

  while (!temp_stack1.empty()) {
    min = temp_stack1.top();
    temp_stack1.pop();
    temp_stack2.push(min);

    while (!temp_stack1.empty()) {
      v0 = temp_stack1.top();
      temp_stack1.pop();

      if (v0 < min) {
        min = v0;
      }
      temp_stack2.push(v0);  // reserve a copy
    }

    while (!temp_stack2.empty()) {
      v0 = temp_stack2.top();
      temp_stack2.pop();
      if (min == v0) {
        s.push(v0);
      } else {
        temp_stack1.push(v0);
      }
    }
  }
}

void sort_stack_with_1add_stack(std::stack<int> &stack) {
  int value, min_value;
  std::stack<int> temp_stack;

  while (!stack.empty()) {
    value = stack.top();
    stack.pop();

    temp_stack.push(value);
  }

  while (!temp_stack.empty()) {
    min_value = temp_stack.top();
    std::cout << "min_value = " << min_value << std::endl;
    temp_stack.pop();

    while (!stack.empty() && stack.top() > min_value) {
      value = stack.top();
      std::cout << "value = " << value << std::endl;
      stack.pop();

      temp_stack.push(value);

    }

    stack.push(min_value);
  }
}

int test() {
  std::stack<int> stack;
  stack.push(3);
  stack.push(1);
  stack.push(2);
  stack.push(0);
  stack.push(-1);
  stack.push(-3);
  stack.push(7);
  stack.push(7);

  print_stack(stack);

  sort_stack_with_1add_stack(stack);

  print_stack(stack);

  return 1;
}

}

#endif /* _SORT_STACK_ASCENDING_H_ */
