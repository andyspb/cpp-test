/*
 * ipc.h
 *
 *  Created on: Nov 23, 2016
 *      Author: andy
 */

#ifndef SRC_IPC_IPC_H_
#define SRC_IPC_IPC_H_

#include "unnamed_pipes.h"

namespace ipc {

TEST_RESULT test() {
  __SCOPE_LOG__;

  assert(unnamed_pipes::test());

  RETURN_OK();
}

}  // namespace ipc

#endif /* SRC_IPC_IPC_H_ */
