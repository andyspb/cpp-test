/*
 * test_2.h
 *
 *  Created on: Jun 27, 2016
 *      Author: andy
 */

#ifndef SRC_TERAMIND_TERRAMIND_2_H_
#define SRC_TERAMIND_TERRAMIND_2_H_

namespace terramind_2 {

// Write some short C or C++ code to generate a stack overflow. *
void stackOverFlow() {
  return stackOverFlow();
}
void stack_overflow() {
  stackOverFlow();
//  system("pause");
}

TEST_RESULT test() {
  __SCOPE_LOG__;

  RETURN_OK();
}

}  // namespace terramind_2

#endif /* SRC_TERAMIND_TERRAMIND_2_H_ */
