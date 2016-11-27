/*
 * unnamed_pipes.h
 *
 *  Created on: Nov 24, 2016
 *      Author: andy
 */

#ifndef SRC_IPC_UNNAMED_PIPES_H_
#define SRC_IPC_UNNAMED_PIPES_H_


#include <unistd.h>
#include <stdio.h>
#include <errno.h>

namespace unnamed_pipes {


TEST_RESULT test() {
  __SCOPE_LOG__;

  int ret_val;
  int pfd[2];
  char buff[32];
  char string1[]="String for pipe I/O";

  LOG(INFO) << "string1:" << string1 << " strlen=" << strlen(string1);

#if defined(__WIN64__)
  ret_val = pipe(pfd);                 /* Create pipe */
  if (ret_val != 0) {             /* Test for success */
    printf("Unable to create a pipe; errno=%d\n",errno);

    exit(1);                         /* Print error message and exit */
  }

  if (fork() == 0) {
     /* child program */
     close(pfd[0]); /* close the read end */
     ret_val = write(pfd[1],string1,strlen(string1)); /*Write to pipe*/
     if (ret_val != (int)strlen(string1)) {
        printf("Write did not return expected value\n");
        exit(2);                       /* Print error message and exit */
     }
  }

  else {
     /* parent program */
     close(pfd[1]); /* close the write end of pipe */
     ret_val = read(pfd[0],buff,strlen(string1)); /* Read from pipe */
     if (ret_val != (int)strlen(string1)) {
        printf("Read did not return expected value\n");
        exit(3);                       /* Print error message and exit */
     }
     //printf("parent read %s from the child program\n",buff);
     LOG(INFO) << "parent read "
         << buff << " from the child program";
  }
#endif
  RETURN_OK();
}

}  // namespace unnamed_pipes


#endif /* SRC_IPC_UNNAMED_PIPES_H_ */
