#ifndef _ALGO_39_H
#define _ALGO_39_H
#include "common_data.h"
//Given an array of characters. How would you reverse it. ?
//How would you reverse it without using indexing in the array.

void algo_39() {
  printf("algo 39 test:\n");
  char str[] = { 'a', 'b', 'c', 'd', 'e' };
  unsigned int size = sizeof(str) / sizeof(str[0]);
  for (unsigned int i = 0; i < size; i++) {
    printf(" %c", str[i]);
  }
  printf("\n");

  char *a = str;
  char *b = str + (size - 1);

  while (a < b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
    ++a;
    --b;
  }
  for (unsigned int i = 0; i < size; i++) {
    printf(" %c", str[i]);
  }
  printf("\n");

}

#endif //_ALGO_39_H
