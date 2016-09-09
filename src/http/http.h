/*
 * http.h
 *
 *  Created on: Apr 17, 2016
 *      Author: andy
 */

#ifndef SRC_HTTP_HTTP_H_
#define SRC_HTTP_HTTP_H_

#include "server.h"

namespace http {

TEST_RESULT test() {
  __SCOPE_LOG__;
  assert(http_server::test());
  RETURN_OK();
}

}  // namespace http


#endif /* SRC_HTTP_HTTP_H_ */
