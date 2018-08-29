#pragma once
#include <cstdio>
namespace search_test {
#define EOS '\0'

void brute_force_searh(char *x, char *y, int m) {
  int i;
  /* looking till end, possible till n-m */
  for (i = 0; *y != EOS; i++, y++) {
    if (memcmp(y, x, m) == 0) {
      printf("found at %d\n", i);
    }
  }
}

// good when array is sorted 
int binary_search(int *arr, int lb, int ub, int key) {
  while (1) {
    int piv = lb - (lb - ub) / 2;
    if (key < arr[piv]) {
      ub = piv - 1;
    } else if (key > arr[piv]) {
      lb = piv + 1;
    } else {
      return piv;
    }
    if (lb > ub) {
      // not found
      return -1;
    }
  }
}

}
