/*
 * server.h
 *
 *  Created on: Aug 11, 2015
 *      Author: andy
 */

#ifndef SRC_HTTP_SERVER_SINGLE_THREAD_H_
#define SRC_HTTP_SERVER_SINGLE_THREAD_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#ifdef __WIN32__
# include <winsock2.h>
#else
# include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#endif

#ifdef __WIN32__
typedef int socklen_t;
#endif

namespace server_single_thread {

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;

  char response[] = "HTTP/1.1 200 OK\r\n"
      "Content-Type: text/html; charset=UTF-8\r\n\r\n"
      "<!DOCTYPE html><html><head><title>Bye-bye baby bye-bye</title>"
      "<style>body { background-color: #111 }"
      "h1 { font-size:4cm; text-align: center; color: black;"
      " text-shadow: 0 0 2mm red}</style></head>"
      "<body><h1>Goodbye, world!</h1></body></html>\r\n";

  int one = 1, client_fd;
  struct sockaddr_in svr_addr, cli_addr;
  socklen_t sin_len = sizeof(cli_addr);

  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    LOG(INFO) << "can't open socket";
    return 0;
  }
#ifndef WIN32
  {
  setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &one, sizeof(int));
  }
#endif

  int port = 8080;
  svr_addr.sin_family = AF_INET;
  svr_addr.sin_addr.s_addr = INADDR_ANY;
  svr_addr.sin_port = htons(port);

  if (bind(sock, (struct sockaddr *) &svr_addr, sizeof(svr_addr)) == -1) {
    close(sock);
    LOG(INFO) << "Can't bind";
    return 0;
  }

  listen(sock, 5);
  while (1) {
    client_fd = accept(sock, (struct sockaddr *) &cli_addr, &sin_len);
    LOG(INFO) << "got connection, client_fd:" << client_fd;

    if (client_fd == -1) {
      perror("Can't accept");
      continue;
    }
    write(client_fd, response, sizeof(response) - 1); /*-1:'\0'*/
    close(client_fd);
    LOG(INFO) << "closed client_fd:" <<client_fd;
  }

  RETURN_OK();
}

}

#endif /* SRC_HTTP_SERVER_SINGLE_THREAD_H_ */
