/*
 * test.h
 *
 *  Created on: Jan 15, 2016
 *      Author: andy
 */

#ifndef SRC_LGE_TEST_H_
#define SRC_LGE_TEST_H_

#include "antipattern.h"
#include "camera.h"
#include "webrtc.h"

namespace lge {


TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;

//  assert(webrtc::test());
  assert(anti_pattern::test());
  assert(camera::test());

  RETURN_OK();
}


}  // namespace lge


#endif /* SRC_LGE_TEST_H_ */
