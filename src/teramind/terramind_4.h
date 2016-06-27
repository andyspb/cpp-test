/*
 * test_4.h
 *
 *  Created on: Jun 27, 2016
 *      Author: andy
 */

#ifndef SRC_TERAMIND_TERRAMIND_4_H_
#define SRC_TERAMIND_TERRAMIND_4_H_

namespace terramind_4 {

// Write some short C or C++ code that slowly leaks memory until
// all the resources are consumed. *
void memory_leak() {
  while (true) {
    int * n = new int;
  }
}

TEST_RESULT test() {
  __SCOPE_LOG__;

  RETURN_OK();
}

}  // namespace terramind_3

#endif /* SRC_TERAMIND_TERRAMIND_4_H_ */
