/*
 * array.h
 *
 *  Created on: Nov 17, 2014
 *      Author: andy
 */

#ifndef ARRAY_H_
#define ARRAY_H_

#include "array_2d.h"

#include <stdio.h>
#include <stdlib.h>

namespace array_ {

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;

  assert(array_2d::test());

  RETURN_OK();
}

}  // namespace array_

#endif /* ARRAY_H_ */
