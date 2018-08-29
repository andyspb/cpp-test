/*
 * blockchain.h
 *
 *  Created on: Feb 27, 2016
 *      Author: andy
 */

#ifndef SRC_BLOCKCHAIN_BLOCKCHAIN_H_
#define SRC_BLOCKCHAIN_BLOCKCHAIN_H_

#include "hash_function_string.h"

#include <iostream>

namespace blockchain {

TEST_RESULT test() {
  __SCOPE_LOG__;

  std::cout << "from blockchain::test\n";

//  assert(hash_function_string::test());
  RETURN_OK();
}

}  // namespace blockchain


#endif /* SRC_BLOCKCHAIN_BLOCKCHAIN_H_ */
