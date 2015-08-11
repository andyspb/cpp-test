/*
 * server_threaded.h
 *
 *  Created on: Aug 11, 2015
 *      Author: andy
 */

#ifndef SRC_HTTP_SERVER_THREADED_H_
#define SRC_HTTP_SERVER_THREADED_H_

#ifdef __WIN32__
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

void child(int fd) {
  char outbuf[MAX_LINE + 1];
  size_t outbuf_used = 0;
  ssize_t result;

  while (1) {
    char ch;
    result = recv(fd, &ch, 1, 0);
    if (result == 0) {
      break;
    } else if (result == -1) {
      perror("read");
      break;
    }

    if (ch == '\n') {
      send(fd, outbuf, outbuf_used, 0);
      outbuf_used = 0;
      continue;
    }
  }
}

void run(void) {
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
    return;
  }

  if (listen(listener, 16) < 0) {
    perror("listen");
    return;
  }

  while (1) {
    struct sockaddr_storage ss;
    socklen_t slen = sizeof(ss);
    int fd = accept(listener, (struct sockaddr*) &ss, &slen);
    if (fd < 0) {
      perror("accept");
    } else {
#ifndef WIN32
      if (fork() == 0) {
        child(fd);
        exit(0);
      }
#else
      std::thread(child, fd);
#endif
    }
  }
}

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;
  run();
  RETURN_OK();
}

}  // namespace server_threaded

#endif /* SRC_HTTP_SERVER_THREADED_H_ */
