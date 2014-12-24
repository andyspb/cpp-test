#ifndef TEST_1_2_REVERSE_C_STRING_H_
#define TEST_1_2_REVERSE_C_STRING_H_

#include <iostream>
// Write code to reverse a C-Style String (C-String means that “abcd”
// is represented as five characters, including the null character )
// This is a classic interview question
// The only “gotcha” is to try to do it in place,
// and to be careful for the null character
namespace test_1_2_reverse_c_string {
void reverse(char* str) {
  char *end = str;
  char tmp;
  if (str) {
    while (*end) {
      ++end;
    }
    --end;
    while(str<end) {
      tmp = *str;
      *str++ = *end;
      *end-- = tmp;
    }
  }
}

int test() {
  std::cout << "Test 1.2" << std::endl;
  char str[] = "test str";
  std::cout << str << std::endl;
  reverse(str);
  std::cout << str << std::endl;
  return 1;
}
} // namespace test_1_2
#endif /* TEST_1_2_REVERSE_C_STRING_H_ */
