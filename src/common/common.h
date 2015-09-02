/*
 * common.h
 *
 *  Created on: Aug 21, 2015
 *      Author: andy
 */

#ifndef SRC_COMMON_COMMON_H_
#define SRC_COMMON_COMMON_H_

#include "../logger/logger.h"

#include "binary_tree.h"
#include "binary_search_tree.h"
#include "bplustree.h"
#include "circular_que.h"
#include "constants.h"
#include "graph.h"
#include "linked_list.h"
#include "node.h"
#include "red_black_tree.h"
#include "avl_tree.h"
#include "iterator.h"

namespace common {

TEST_RESULT test() {

  assert(bplus_tree::test());

  RETURN_OK();
}

}  // namespace common

#endif /* SRC_COMMON_COMMON_H_ */
