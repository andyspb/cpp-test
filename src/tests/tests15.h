// tests15.h
// author: andrey.krutogolov@gmail.com
// date:   28.03.2013

#ifndef TESTS15_H_
#define TESTS15_H_

#include <stdio.h>

namespace tests15 {

int main() {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsequence-point"

  int i = 0;
  i = i++ + ++i;
  printf("Example:\nint i = 0;\ni = i++ + ++i;\nResult:i=%d\n\n", i);  // 3

  i = 1;
  i = (i++);
  printf("Example:\nint i = 1;\ni = (i++);\nResult:i=%d\n\n", i);  // 2 Should be 1, no ?

  volatile int v = 0;
  v = v++ + ++v;
  printf("Example:\nvolatile int v = 0;\nv = v++ + ++v;\nResult:v=%d\n\n", v);  // 1

  v = 1;
  v = (v++);
  printf("Example:\nvolatile v = 1;\nv = (v++);\nResult:v=%d\n\n", v);  // 2 Should also be one, no ?

  register int r = 0;
  r = r++ + ++r;
  printf("Example:\nregister int r = 0;\nr = r++ + ++r;\nResult:r=%d\n", r);  // 3 (Should be the same as u ?)

#pragma GCC diagnostic pop

  return 0;
}

}  // namespace tests15

#endif  // TESTS15_H_
