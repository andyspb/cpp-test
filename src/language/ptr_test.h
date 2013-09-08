#pragma once
#include <stdio.h>

void algo_78() {
  printf("algo_78 test:\n");
  int *a = 0;
  char *c = 0;
  *(a) = 20;
  *c = *a;
  printf("%c", *c);
}
