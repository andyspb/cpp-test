/*
 * 3_1_impl_stack_with_array.h
 *
 *  Created on: 28 ���. 2014 �.
 *      Author: andy
 */

#ifndef _IMPL_STACK_WITH_ARRAY_H_
#define _IMPL_STACK_WITH_ARRAY_H_

#include <exception>
#include <string>

namespace impl_three_stack_with_arr {

class Exception : public std::exception {
 public:
  Exception(std::string msg)
      : message(msg) {
  }
  ~Exception() throw() {
  }

  virtual const char* what() const throw () {
    std::string msg = "Exception: " + message;
    return msg.c_str();
  }

 private:
  std::string message;
};

int stackSize = 100;
int * buffer = new int[stackSize * 3];
int stackPointer[] = { -1, -1, -1 };

/* returns index of top of stack "stackNurrr"J in absolute terms */
int absTopOfStack(int stackNum) {
  return stackNum * stackSize + stackPointer[stackNum];
}

int peek(int stackNum) {
  int index = absTopOfStack(stackNum);
  return buffer[index];
}

bool isEmpty(int stackNum) {
  return stackPointer[stackNum] == -1;
}

void push(int stackNum, int value) throw (Exception) {
  /* Check if we have space */
  if (stackPointer[stackNum] + 1 >= stackSize) {
    // Last element
    throw Exception("0ut of space.");
  }
  /* Increment stack pointer and then update top value */
  stackPointer[stackNum]++;
  buffer[absTopOfStack(stackNum)] = value;
}

int pop(int stackNum) throw(Exception) {
  if (stackPointer[stackNum] == -1) {
    throw new Exception("Trying to pop an empty stack.");
  }
  int value = buffer[absTopOfStack(stackNum)];  // Get top
  buffer[absTopOfStack(stackNum)] = 0;// Clear index
  stackPointer[stackNum]--;// Decrement pointer
  return value;
}

int test() {
  return 1;
}

}  // impl_stack_with_arr

#endif /* _IMPL_STACK_WITH_ARRAY_H_ */
