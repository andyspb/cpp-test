/*
 * server.h
 *
 *  Created on: Aug 11, 2015
 *      Author: andy
 */

#ifndef SRC_HTTP_SERVER_H_
#define SRC_HTTP_SERVER_H_

#ifdef __linux__
#include "server_single_thread.h"
#include "server_threaded.h"
#endif // __linux__

namespace http_server {

TEST_RESULT test() {
  __SCOPE_LOG__;

#ifdef __linux__
  assert(server_single_thread::test());
  assert(server_threaded::test());
#endif // __linux__
  RETURN_OK();
}

}  // namespace http_server

#endif /* SRC_HTTP_SERVER_H_ */
