/*
 * threads_posix.h
 *
 *  Created on: 22 мая 2016 г.
 *      Author: andy
 */

#ifndef SRC_THREAD_THREADS_POSIX_H_
#define SRC_THREAD_THREADS_POSIX_H_

#include <stdio.h>
#include <pthread.h>

namespace threads_posix {

#define NTHREADS 10
void *thread_function(void *);
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;
  pthread_t thread_id[NTHREADS];
  int i, j;

  for (i = 0; i < NTHREADS; i++) {
    pthread_create(&thread_id[i], NULL, thread_function, NULL);
  }

  for (j = 0; j < NTHREADS; j++) {
    pthread_join(thread_id[j], NULL);
  }

  /* Now that all threads are complete I can print the final result.     */
  /* Without the join I could be printing a value before all the threads */
  /* have been completed.                                                */

  printf("Final counter value: %d\n", counter);

  RETURN_OK();
}

void *thread_function(void *dummyPtr) {
  printf("Thread number %ld\n", static_cast<long int>(pthread_self()));
  pthread_mutex_lock(&mutex1);
  counter++;
  pthread_mutex_unlock(&mutex1);
  return 0;
}

}  // namespace threads_posix

#endif /* SRC_THREAD_THREADS_POSIX_H_ */
