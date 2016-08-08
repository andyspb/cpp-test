//  hash_function_sample.h
//  author: andrey.krutogolov@gmail.com
//  date:   Dec 10, 2012

#ifndef HASH_FUNCTION_SAMPLE_H_
#define HASH_FUNCTION_SAMPLE_H_

#include <iostream>
#include <vector>

namespace hash_function_test {

typedef std::vector<std::string>::iterator my_iter;

size_t hash(const std::string &data) {
  size_t h(0);
  for (int i = 0; i < static_cast<int>(data.length()); i++) {
    h = (h << 6) ^ (h >> 26) ^ data[i];
  }
  return h;
}

int hash2(string word) {
  int result = 0;
  for (size_t i = 0; i < word.length(); ++i) {
    result += word[i] * pow((float) 31, (int) i);
  }
  return result;
}

TEST_RESULT test() {
  __SCOPE_LOG__;
  std::vector<std::string> test_strings;
  test_strings.push_back("one");
  test_strings.push_back("two");
  test_strings.push_back("three");
  test_strings.push_back("four");
  test_strings.push_back("five");
  test_strings.push_back("six");
  test_strings.push_back("one");
  for (my_iter it = test_strings.begin(); it != test_strings.end(); ++it) {
    std::cout << "hash(\"" << *it << "\") = " << hash(*it) << std::endl;
  }

  for (my_iter it = test_strings.begin(); it != test_strings.end(); ++it) {
    std::cout << "hash2(\"" << *it << "\") = " << hash2(*it) << std::endl;
  }

  RETURN_OK();
}

}  //hash_function_test

#endif  // HASH_FUNCTION_SAMPLE_H_
