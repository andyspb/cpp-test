#ifndef _MULTIPLY_7_H
#define _MULTIPLY_7_H

//Give a fast way to multiply a number by 7.

int multiply_by_7(int x) {
  int temp = x;
  x = x << 3;
  return x - temp;
}

void algo_15() {
  printf("algo 15:a fast way to multiply a number by 7\n");

  int x = 0;
  printf("multiply_by_7(%d)=%d\n", x, multiply_by_7(x));

  x = 1;
  printf("multiply_by_7(%d)=%d\n", x, multiply_by_7(x));

  x = 5;
  printf("multiply_by_7(%d)=%d\n", x, multiply_by_7(x));

  x = 7;
  printf("multiply_by_7(%d)=%d\n", x, multiply_by_7(x));

  x = 111;
  printf("multiply_by_7(%d)=%d\n", x, multiply_by_7(x));
}

#endif  //_MULTIPLY_7_H
