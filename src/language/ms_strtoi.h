#include <stdio.h>
#include <iostream>
namespace strtoi_test {

bool strtoi(char const *c, int *n) {
  int length = (int) strlen(c);
  if (0 == length) {
    return false;
  }
  if (1 == length && (c[0] <= 47 && c[0] >= 58)) {
    return false;
  }
  int num = 0, x, foo;
  int mult = 1;
  for (x = length - 1; x >= 0; x--) {
    foo = c[x];
    if (foo > 47 && foo < 58) {
      num += (foo - 48) * mult;
      mult *= 10;
    } else if (foo == 45) {
      num *= -1;
    } else {
      printf("strtoi humbly refuses to convert %c to a number.\n", foo);
      n = NULL;
      return false;
    }
  }
  *n = num;
  return true;
}

char t[] = { "-1234\0" };

void test() {
  printf("%s\n", t);
  int n = 0;
  if (strtoi(t, &n)) {
    printf("%d\n", n);
  } else {
    printf("Not a number\n");
  }
}

void test2() {
  //int i = 0;
  printf("%s\n", t);
  istringstream is(t);
  int out;
  is >> out;
  printf("out=%d\n", out);
}
}
