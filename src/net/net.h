/*
 * net.h
 *
 *  Created on: Sep 7, 2015
 *      Author: andy
 */

#ifndef SRC_NET_NET_H_
#define SRC_NET_NET_H_

#include "server.h"
#include "client.h"

#include <thread>

namespace net {

void server() {
  __SCOPE_LOG__;
#ifdef __linux__
  server::test();
#endif
}

void client() {
  __SCOPE_LOG__;
#ifdef __linux__
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  client::test();
#endif
}

TEST_RESULT test() {
  __SCOPE_LOG__;
  LOG(INFO) << __PRETTY_FUNCTION__;
#ifdef __linux__
  std::thread t_srv(server);
  std::thread t_client(client);

  t_srv.join();
  t_client.join();
#endif
  RETURN_OK();
}
}  // namespace net

#endif /* SRC_NET_NET_H_ */
