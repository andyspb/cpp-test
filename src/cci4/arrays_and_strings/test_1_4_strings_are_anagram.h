#ifndef TEST_1_4_STRINGS_ARE_ANAGRAM_H_
#define TEST_1_4_STRINGS_ARE_ANAGRAM_H_

#include <iostream>
#include <algorithm>
// Write a method to decide if two strings are anagrams or not.

namespace test_1_4_strings_are_anagram {
// Solution #1: Sort the strings
bool anagram(std::string s, std::string t) {
  std::sort(s.begin(), s.end());
  std::sort(t.begin(), t.end());
  return s.compare(t) == 0;
}

// Solution #2: Check if the two strings have identical counts for each unique char.
bool anagram2(std::string s, std::string t) {
  if (s.length() != t.length()) {
    return false;
  }
  int letters[256] = { 0 };
  int num_unique_chars = 0;
  int num_completed_t = 0;
  char *s_array = new char[s.length() + 1];
  strcpy(s_array, s.c_str());
  for (int i = 0; i < (int) s.length(); ++i) {
    // count number of each char in s.
    if (letters[(int) s_array[i]] == 0) {
      ++num_unique_chars;
    }
    ++letters[(int) s_array[i]];
  }
  for (int i = 0; i < (int) t.length(); ++i) {
    int c = (int) t.at(i);
    if (letters[c] == 0) {  // Found more of char c in t than in s.
      return false;
    }
    --letters[c];
    if (letters[c] == 0) {
      ++num_completed_t;
      if (num_completed_t == num_unique_chars) {
        // itÕs a match if t has been processed completely
        return i == (int) t.length() - 1;
      }
    }
  }
  return false;
}

int test() {
  std::cout << "Test 1.4" << std::endl;
  std::string str1 = "str1";
  std::string rts1 = "rts1";
  std::string res = anagram(str1, rts1) ? "are anagrams" : "are not anagrams";
  std::cout << str1 << " and " << rts1 << " " << res << std::endl;

  str1 = "aaabbbccc1";
  rts1 = "bbba1cacac";
  res = anagram2(str1, rts1) ? "are anagrams" : "are not anagrams";
  std::cout << str1 << " and " << rts1 << " " << res << std::endl;

  str1 = "aaabbbccc1";
  rts1 = "12";
  res = anagram2(str1, rts1) ? "are anagrams" : "are not anagrams";
  std::cout << str1 << " and " << rts1 << " " << res << std::endl;

  return 1;
}
}  // test_1_4

#endif /* TEST_1_4_STRINGS_ARE_ANAGRAM_H_ */
