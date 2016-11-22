/*
 * cast.h
 *
 *  Created on: 21 но€б. 2016 г.
 *      Author: andy
 */

#ifndef SRC_CAST_CAST_H_
#define SRC_CAST_CAST_H_

#include "static_cast.h"

namespace cast {


TEST_RESULT test() {
  __SCOPE_LOG__;
  assert(cast_static_cast_::test());


  RETURN_OK();
}


}  // namespace cast



#endif /* SRC_CAST_CAST_H_ */
