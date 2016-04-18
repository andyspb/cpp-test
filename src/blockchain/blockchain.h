/*
 * blockchain.h
 *
 *  Created on: Feb 27, 2016
 *      Author: andy
 */

#ifndef SRC_BLOCKCHAIN_BLOCKCHAIN_H_
#define SRC_BLOCKCHAIN_BLOCKCHAIN_H_

#include "hash_function.h"

namespace blockchain {

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;
  assert(hash_function::test());
  RETURN_OK();
}

}  // namespace blockchain


#endif /* SRC_BLOCKCHAIN_BLOCKCHAIN_H_ */
