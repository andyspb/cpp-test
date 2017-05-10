/*
 * common.h
 *
 *  Created on: Aug 21, 2015
 *      Author: andy
 */

#ifndef SRC_COMMON_COMMON_H_
#define SRC_COMMON_COMMON_H_

#include "../logger/logger.h"

#include "tree.h"
#include "circular_que.h"
#include "constants.h"
#include "graph.h"
#include "list.h"
#include "iterator.h"

namespace common {

TEST_RESULT test() {

  //assert(bplus_tree::test());

  RETURN_OK();
}

}  // namespace common

#endif /* SRC_COMMON_COMMON_H_ */
