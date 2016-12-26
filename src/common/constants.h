/*
 * constants.h
 *
 *  Created on: Jul 13, 2015
 *      Author: andy
 */

#ifndef SRC_COMMON_CONSTANTS_H_
#define SRC_COMMON_CONSTANTS_H_

#define RESULT_OK 1
#define RESULT_FAIL 0

#define RETURN_OK() \
  return RESULT_OK

#define RETURN_FAIL() \
  return RESULT_FAIL

#define TEST_RESULT int
#define TEST_OK 1
#define OK 1
#define FALSE 0

class Result {
  void operator()() {

  }
};


namespace constants {

}  // constants

#endif /* SRC_COMMON_CONSTANTS_H_ */
