/*
 * test.h
 *
 *  Created on: 4 ���. 2015 �.
 *      Author: andy
 */

#ifndef SRC_OPENCV_TEST_H_
#define SRC_OPENCV_TEST_H_

namespace opencv {

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;

  RETURN_OK();
}

}

#endif /* SRC_OPENCV_TEST_H_ */
