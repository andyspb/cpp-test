#include <stdio.h>
#include <algorithm>
using namespace std;
namespace reverse_chars {
void test() {
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
}
}

