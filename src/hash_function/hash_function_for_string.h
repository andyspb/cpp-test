/*
 * string_hash_function.h
 *
 *  Created on: Aug 11, 2016
 *      Author: andy
 */

#ifndef SRC_HASH_FUNCTION_HASH_FUNCTION_FOR_STRING_H_
#define SRC_HASH_FUNCTION_HASH_FUNCTION_FOR_STRING_H_

#include <iostream>
#include <string>

namespace hash_function_for_string {

const char* test_string[10] = {
    "test1test2",
    "test2test2",
    "test2test2",
    "",
    "1",
    "2",
    "test7test2test2test2test2test2",
    "test8test2",
    "test9test2test2test2test2test2test2test2test2test2test2test2test2test2test2test2test2test2test2test2test2test2test2",
    "test10test2"
};

unsigned long hash(const char *str) {

  unsigned long HASH = 5381;
  int c;
  while (c = *str++) {
    HASH = ((HASH << 5) + HASH) + c; /* hash * 33 + c */
  }
  return HASH;

}

TEST_RESULT test() {
  __SCOPE_LOG__;

  for (int i = 0; i<10; ++i) {
    std::cout << test_string[i]<< ": " << hash(test_string[i]) << std::endl;
  }
 RETURN_OK();
}

}  // namespace string_hash_function

#endif /* SRC_HASH_FUNCTION_HASH_FUNCTION_FOR_STRING_H_ */
