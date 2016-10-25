#ifndef _REVERSE_SENTENSE_H_
#define _REVERSE_SENTENSE_H_

#include <string>
#include <iostream>

namespace reverse_sentense {
void rev_word(char *start, char *end) {
  char temp;
  while (start < end) {
    temp = *start;
    *start++ = *end;
    *end-- = temp;
  }
}

void rev_sentense(char * str) {
//#pragma warning(disable :4267)
  int length = (int) strlen(str);
  if (length <= 1) {
    return;
  }
  char *end, *x, *y;
  end = &str[length];
  rev_word(str, end - 1);;
  x = str - 1;
  y = str;
  while (x++ < end) {
    if (*x == '\0' || *x == ' ') {
      rev_word(y, x - 1);
      y = x + 1;
    }
  }
}

TEST_RESULT test() {
  __SCOPE_LOG__;
  char str[] = "The dog is fast";
  std::cout << str << std::endl;
  rev_sentense(str);
  std::cout << str << std::endl;
  RETURN_OK();
}
} // namespace reverse_sentense

#endif // _REVERSE_SENTENSE_H_

