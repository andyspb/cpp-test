#ifndef _MULTIPLY_7_H
#define _MULTIPLY_7_H

//Give a fast way to multiply a number by 7.
namespace multiply_by_7_ {
int multiply_by_7(int x) {
  int temp = x;
  x = x << 3;
  return x - temp;
}

void test() {
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

}  // multiply_by_7
#endif  //_MULTIPLY_7_H
