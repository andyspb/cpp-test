#ifndef TEST_1_8_CHECK_STRING_ROTATION_IF_HAS_SUBSTR_H_
#define TEST_1_8_CHECK_STRING_ROTATION_IF_HAS_SUBSTR_H_

#include <string>
// Assume you have a method isSubstring which checks
// if one word is a substring of another Given two strings, s1 and s2,
// write code to check if s2 is a rotation of s1 using only one call to
// isSubstring (i e , ÒwaterbottleÓ is a rotation of ÒerbottlewatÓ)
namespace test_1_8_check_string_rotation_if_has_substr {
// Just do the following checks
// Check if length(s1) == length(s2) If not, return false
// Else, concatenate s1 with itself and see whether s2 is substring of the result
// input: s1 = apple, s2 = pleap ==> apple is a substring of pleappleap
// input: s1 = apple, s2 = ppale ==> apple is not a substring of ppaleppale

bool isRotation(std::string s1, std::string s2) {
  size_t len = s1.length();
  // check that s1 and s2 are equal length and not empty
  if (len == s2.length() && len > 0) {
    // concatenate s1 and s1 within new buffer
    std::string s1s1 = s1 + s1;
    // std find;
    //return isSubstring(s1s1, s2);
    return (s1s1.find(s2) != std::string::npos);
  }
  return false;
}
int test() {
  std::cout << "Test 1.8" << std::endl;
  std::string str1 = "apple";
  std::string str2 = "pleap";
  std::string res = isRotation(str1, str2)?"is rotation":"is not rotation";
  std::cout << str2 << " " << res << " for " << str1 << std::endl;

  str1 = "apple";
  str2 = "ppale";
  res = isRotation(str1, str2)?"is rotation":"is not rotation";
  std::cout << str2 << " " << res << " for " << str1 << std::endl;

  return 1;
}
} // namespace test_1_8

#endif /* TEST_1_8_CHECK_STRING_ROTATION_IF_HAS_SUBSTR_H_ */
