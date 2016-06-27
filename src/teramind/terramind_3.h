/*
 * test_3.h
 *
 *  Created on: Jun 27, 2016
 *      Author: andy
 */

#ifndef SRC_TERAMIND_TERRAMIND_3_H_
#define SRC_TERAMIND_TERRAMIND_3_H_

namespace terramind_3 {

// Write some short C or C++ code to generate a segmentation fault. *
void segmentation_fault() {
  const char *s = 0;
  printf("%c\n", s[0]);
}

TEST_RESULT test() {
  __SCOPE_LOG__;

  RETURN_OK();
}

}  // namespace terramind_3

#endif /* SRC_TERAMIND_TERRAMIND_3_H_ */
