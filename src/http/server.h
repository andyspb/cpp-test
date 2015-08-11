/*
 * server.h
 *
 *  Created on: Aug 11, 2015
 *      Author: andy
 */

#ifndef SRC_HTTP_SERVER_H_
#define SRC_HTTP_SERVER_H_

#include "server_single_thread.h"
#include "server_threaded.h"

namespace http_server {

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;

//  assert(server_single_thread::test());
  assert(server_threaded::test());

  RETURN_OK();
}

}  // namespace http_server


#endif /* SRC_HTTP_SERVER_H_ */
