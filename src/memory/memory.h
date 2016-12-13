/*
 * memory.h
 *
 *  Created on: Jul 15, 2015
 *      Author: andy
 */

#ifndef SRC_MEMORY_MEMORY_H_
#define SRC_MEMORY_MEMORY_H_

#include "alignment.h"
#include "allocate_1024_bytes_of_memory.h"
#include "allocator.h"
#include "habrhabr.h"
#include "mem_test.h"

namespace memory {

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;
  assert(alignment::test());
  assert(mem_test::test());

  RETURN_OK();
}

}  // namespace memory


#endif /* SRC_MEMORY_MEMORY_H_ */
