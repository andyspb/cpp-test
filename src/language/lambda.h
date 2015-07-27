/*
 * lamba.h
 *
 *  Created on: Jul 13, 2015
 *      Author: andy
 */

#ifndef SRC_LANGUAGE_LAMBDA_H_
#define SRC_LANGUAGE_LAMBDA_H_

namespace language_lambda {

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;
  // generic lambda, operator() is a template with two parameters
  auto glambda = [](auto a, auto&& b) { return a < b; };
  int a = 1;
  int&& b =2;
  LOG(INFO) << "glambda(1,2) = " << glambda(a,b);

  return RESULT_OK;
}

}  // namespace language_



#endif /* SRC_LANGUAGE_LAMBDA_H_ */
