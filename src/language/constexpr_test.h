/*
 * constexpr_test.h
 *
 *  Created on: Jul 13, 2015
 *      Author: andy
 */

#ifndef SRC_LANGUAGE_CONSTEXPR_TEST_H_
#define SRC_LANGUAGE_CONSTEXPR_TEST_H_

namespace constexpr_test {

constexpr int mult(int i, int j) {
  return i*j;
}


TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;
  auto r = mult(2,3);
  std::cout<< "r = " << r << std::endl;
  return RESULT_OK;
}


}  // namespace constexpr_test

#endif /* SRC_LANGUAGE_CONSTEXPR_TEST_H_ */
