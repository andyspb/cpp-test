/*
 * teramind.h
 *
 *  Created on: 8 рту. 2015 у.
 *      Author: andy
 */

#ifndef SRC_TERAMIND_TERAMIND_H_
#define SRC_TERAMIND_TERAMIND_H_

namespace teramind {

// If a struct has some members of type int and char, how do you compare two
// instances of this struct to see if the members have the same value? *
struct A {
  int a;
  char b;
};

int CompareA(const A& a1, const A& a2) {
  long long l1 = 0;
  long long l2 = 0;
  l1 = ((long long) a1.a << 32) + a1.b;
  l2 = ((long long) a2.a << 32) + a2.b;

  if (l1 > l2)
    return 1;
  else if (l2 > l1)
    return -1;
  else
    return 0;
}

// Write some short C or C++ code to generate a stack overflow. *

void stackOverFlow() {
  return stackOverFlow();
}
void stack_overflow() {
  stackOverFlow();
  system("pause");
}
// Write some short C or C++ code to generate a segmentation fault. *
void segmentation_faule() {
  const char *s = 0;
  printf("%c\n", s[0]);
}

// Write some short C or C++ code that slowly leaks memory until
// all the resources are consumed. *
void memory_leak() {
  while (true) {
    int * n = new int;
  }
}

// You have a pointer to some element in a linked list (a => b => c => d => e).
// What is the fastest way to tell if there is a loop in the linked list
// (a => b => c => d => e => a)?
struct List {
  int data;
  List * next;
};

bool find_loop_in_list(List * head) {
  if (!head)
    return false;
  List *fast(head), *slow(head);
  bool has_circle = true;
  do {
    if (fast->next == NULL || fast->next->next == NULL) {
      has_circle = false;
      break;
    }

    fast = fast->next->next;
    slow = slow->next;
  } while (fast != slow);
  return has_circle;
}

// Write a recursive function in C or C++ to calculate the Nth number
// in the Fibonacci sequence. *
unsigned long long fib(int n) {
  if (n == 1)
    return 0ULL;
  else if (n == 2)
    return 1ULL;
  else
    return fib(n - 1) + fib(n - 2);
}
// Fibonacci sequence. *

// What are a few of the functional-style programming methods that are available in C++11? *

// You have a 1TB file containing integers (one number per line). You have 2GB of memory. How do you sort this file as fast as possible?

// Imagine your task is to create a high-traffic web server in C++. What multiplexing options are available to you? Which is the best / most efficient, and why? Which libraries will you consider using?

// What benefit is provided by compiling in "Debug" mode (-O0 in gcc)? *

// What is meant my position-independent code (-fPIC in gcc)? When would you use it? How are EXE and DLL's compiled with this regard in Windows?

// What are some compiler optimizations that you know (ie. loop unrolling, constant folding, etc)? *

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;
  RETURN_OK();
}

}  // namespace teramind

#endif /* SRC_TERAMIND_TERAMIND_H_ */
