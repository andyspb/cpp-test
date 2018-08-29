/*
 * hrank.h
 *
 *  Created on: 16 апр. 2017 г.
 *      Author: andy
 */

#ifndef SRC_HRANK_HRANK_H_
#define SRC_HRANK_HRANK_H_

#include "array_ds.h"

namespace hrank {

TEST_RESULT test() {
  __SCOPE_LOG__;
  assert(array_ds::test());

  RETURN_OK();
}

}  // namespace hrank

#endif /* SRC_HRANK_HRANK_H_ */
