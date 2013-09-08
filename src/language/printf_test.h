#pragma once
#include <stdio.h>
namespace printf_test {

void test() {
  printf("\n%s\n", "1");
  printf("%s", "%s");

  printf("\n%s\n", "2");
  printf("%s", "%x");
}

}
