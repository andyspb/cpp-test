#pragma once
// What are the different ways to implement a condition where the value of x can be either a 0 or a 1.
// Apparently the if then else solution has a jump when written out in assembly.
// if (x == 0) y=a else y=b There is a logical,
// arithmetic and a data structure solution to the above problem.

void condition_x_0_or_1() {
  printf("algo_10 test\n");
  int y, a = 0, b = 9;

  if (x == 0) {
    y = a;
  } else {
    y = b;
  }
}
