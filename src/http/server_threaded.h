/*
 * server_threaded.h
 *
 *  Created on: Aug 11, 2015
 *      Author: andy
 */

#ifndef SRC_HTTP_SERVER_THREADED_H_
#define SRC_HTTP_SERVER_THREADED_H_

#ifdef __GNUC__



#if defined(__WIN32__) || defined (__WIN64__)
# include <winsock2.h>
#else
#include <netinet/in.h>
#include <sys/socket.h>
#endif

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 16384

namespace server_threaded {

constexpr char response[] = "HTTP/1.1 200 OK\r\n"
    "Content-Type: text/html; charset=UTF-8\r\n\r\n"
    "<!DOCTYPE html><html><head><title>Bye-bye baby bye-bye</title>"
    "<style>body { background-color: #111 }"
    "h1 { font-size:4cm; text-align: center; color: black;"
    " text-shadow: 0 0 2mm red}</style></head>"
    "<body><h1>Goodbye, world!</h1></body></html>\r\n";


void child(int fd) {
  LOG(INFO) << __PRETTY_FUNCTION__
      << " fd:" << fd;
  char outbuf[MAX_LINE + 1];
  size_t outbuf_used = 0;
  ssize_t result;

  write(fd, response, sizeof(response) - 1); /*-1:'\0'*/
  close(fd);

//  while (1) {
//    char ch;
//    result = recv(fd, &ch, 1, 0);
//    if (result == 0) {
//      break;
//    } else if (result == -1) {
//      perror("read");
//      break;
//    }
//
//    if (ch == '\n') {
//      send(fd, outbuf, outbuf_used, 0);
//      outbuf_used = 0;
//      continue;
//    }
//  }
  LOG(INFO)  << "exit() fd:" << fd;
}

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;
  int listener;
  struct sockaddr_in sin;
  auto constexpr port = 8080;

  sin.sin_family = AF_INET;
  sin.sin_addr.s_addr = 0;
  sin.sin_port = htons(port);

  listener = socket(AF_INET, SOCK_STREAM, 0);

#ifndef WIN32
  {
    int one = 1;
    setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &one, sizeof(one));
  }
#endif

  if (bind(listener, (struct sockaddr*) &sin, sizeof(sin)) < 0) {
    close(listener);
    LOG(INFO) << "can't bind";
    RETURN_FAIL();
  }

  if (listen(listener, 16) < 0) {
    perror("listen");
    RETURN_FAIL();
  }

  while (1) {
    struct sockaddr_storage ss;
    socklen_t slen = sizeof(ss);
    int client_fd = accept(listener, (struct sockaddr*) &ss, &slen);
    LOG(INFO) << "got connection, client_fd:" << client_fd;
    if (client_fd < 0) {
      LOG(INFO) << "Failed accept, client_fd:" << client_fd;
    } else {
      std::thread t(child, client_fd);
      t.detach();
    }
  }
  RETURN_OK();
}

}  // namespace server_threaded

#endif // __GNUC__
#endif /* SRC_HTTP_SERVER_THREADED_H_ */
