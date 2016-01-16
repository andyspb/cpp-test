#include <stdio.h>
#include <algorithm>

#include "common/constants.h"

using namespace std;
namespace reverse_chars {
TEST_RESULT test() {
//        const char * str = "Hello World!";

  char chars[256] = "Hello World!";
  //strcpy(chars, str);

  unsigned length = (unsigned) strlen(chars);
  printf("chars=%s  size of chars = %d\n", chars, length);
  char * p = chars;
  char * q = chars + length - 1;
  while (p < q) {
    swap(*p++, *q--);
  }

  printf("chars=%s\n", chars);

  RETURN_OK();
}
}

