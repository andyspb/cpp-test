/*
 * hash_function.h
 *
 *  Created on: Feb 27, 2016
 *      Author: andy
 */

#ifndef SRC_BLOCKCHAIN_HASH_FUNCTION_STRING_H_
#define SRC_BLOCKCHAIN_HASH_FUNCTION_STRING_H_

#include <iostream>
#include <functional>
#include <string>

namespace hash_function_string {

unsigned int hash(const char* s, unsigned int seed = 0) {
  unsigned int hash = seed;
  while (*s) {
    hash = hash * 101 + *s++;
  }
  return hash;
}

size_t test_std_hash(const std::string& str) {
  std::hash<std::string> hash;
  return hash(str);
}

TEST_RESULT test() {
  __SCOPE_LOG__;

  std::string s1 = "aaa";
  std::string s2 = "bbb";
  std::string s3 = "Andrey Krutogolov";
  std::string s4 = "aaa";
  std::string s6 = "aaaa";
  std::string s5 = "AndreY KrutogoloV";

  std::cout << s1 << " hash: " << hash(s1.c_str()) << std::endl;
  std::cout << s2 << " hash: " << hash(s2.c_str()) << std::endl;
  std::cout << s3 << " hash: " << hash(s3.c_str()) << std::endl;
  std::cout << s4 << " hash: " << hash(s4.c_str()) << std::endl;
  std::cout << s6 << " hash: " << hash(s6.c_str()) << std::endl;
  std::cout << s5 << " hash: " << hash(s5.c_str()) << std::endl;

  std::cout << s5 << " hash: " << test_std_hash(s5) << std::endl;

  RETURN_OK();
}

}  // namespace hash_function

#endif /* SRC_BLOCKCHAIN_HASH_FUNCTION_STRING_H_ */
