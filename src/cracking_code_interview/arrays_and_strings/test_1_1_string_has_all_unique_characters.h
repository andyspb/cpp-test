#ifndef _TEST_1_1_H
#define _TEST_1_1_H

#include <iostream>
#include <string>
// Implement an algorithm to determine if a string has all unique characters.
// What if you can not use additional data structures?
namespace test_1_1_string_has_all_unique_characters {
// For simplicity, assume char set is ASCII (if not,
// we need to increase the storage size.
// The rest of the logic would be the same)
// NOTE: This is a great thing to point out to your interviewer!
bool isUniqueChars2(std::string str) {
  bool char_set[256] = { false };
  for (int i = 0; i < (int) str.length(); ++i) {
    int val = str.at(i);
    if (char_set[val]) {
      return false;
    }
    char_set[val] = true;
  }
  return true;
}

// We can reduce our space usage a little bit by using a bit vector
// We will assume, in the below code, that the string is only lower
// case a-x through A-Õ This will allow us to use just a single int
bool isUniqueChars(std::string str) {
  int checker = 0;
  for (int i = 0; i < (int) str.length(); ++i) {
    int val = str.at(i) - 'a';
    if ((checker & (1 << val)) > 0) {
      return false;
    }
    checker |= (1 << val);
  }
  return true;
}

int test() {
  std::cout << "Test 1.1" << std::endl;
  std::string str = "Andrey";
  std::string res = isUniqueChars2(str) ? "uniq" : "not uniq";
  std::cout << "Chars in '" << str << "' are " << res << std::endl;
  str = "Krutogolov";
  res = isUniqueChars2(str) ? "uniq" : "not uniq";
  std::cout << "Chars in '" << str << "' are " << res << std::endl;

  str = "qwerry";
  res = isUniqueChars(str) ? "uniq" : "not uniq";
  std::cout << "Chars in '" << str << "' are " << res << std::endl;
  str = "qwerty";
  res = isUniqueChars(str) ? "uniq" : "not uniq";
  std::cout << "Chars in '" << str << "' are " << res << std::endl;
  return 1;
}

} // namespace test_1_1

#endif  // _TEST_1_1_H
