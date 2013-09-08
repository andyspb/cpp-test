#ifndef _BRAINBENCH_1_H_
#define _BRAINBENCH_1_H_

#include <stdlib.h>

#include <iostream>
#include <string>

namespace brainbench_1 {
int test() {
  char BUF1[100];
  char buf2[100];
  char *strptr1;
  char *strptr2;

  strcpy(BUF1, "abcdefghijklmnopqrstuvwxyz");
  strcpy(buf2, "Hello");

  strptr1 = BUF1 + 6;
  strcpy(strptr1, buf2);

  strptr2 = (strptr1 + 8);
  strncpy(strptr2, buf2, 4);

  printf("%s\n", BUF1);
  return 1;
}
} // namespace brainbench_1

#endif // _BRAINBENCH_1_H_
