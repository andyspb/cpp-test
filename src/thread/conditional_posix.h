/*
 * conditional_posix.h
 *
 *  Created on: 22 ��� 2016 �.
 *      Author: andy
 */

#ifndef SRC_THREAD_CONDITIONAL_POSIX_H_
#define SRC_THREAD_CONDITIONAL_POSIX_H_

#ifdef __GNUC__
#include <pthread.h>
#endif // __GNUC__

namespace conditional_posix {
#ifdef __GNUC__

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t condition_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition_cond = PTHREAD_COND_INITIALIZER;

void *functionCount1(void*);
void *functionCount2(void*);
int count = 0;
#define COUNT_DONE  10
#define COUNT_HALT1  3
#define COUNT_HALT2  6

void *functionCount1(void* ptr) {
  for (;;) {
    pthread_mutex_lock(&condition_mutex);
    while (count >= COUNT_HALT1 && count <= COUNT_HALT2) {
      pthread_cond_wait(&condition_cond, &condition_mutex);
    }
    pthread_mutex_unlock(&condition_mutex);

    pthread_mutex_lock(&count_mutex);
    count++;
    printf("Counter value functionCount1: %d\n", count);
    pthread_mutex_unlock(&count_mutex);

    if (count >= COUNT_DONE)
      return (NULL);
  }
  return 0;
}

void *functionCount2(void* ptr) {
  for (;;) {
    pthread_mutex_lock(&condition_mutex);
    if (count < COUNT_HALT1 || count > COUNT_HALT2) {
      pthread_cond_signal(&condition_cond);
    }
    pthread_mutex_unlock(&condition_mutex);

    pthread_mutex_lock(&count_mutex);
    count++;
    printf("Counter value functionCount2: %d\n", count);
    pthread_mutex_unlock(&count_mutex);

    if (count >= COUNT_DONE)
      return (NULL);
  }
  return 0;
}
#endif // __GNUC__

TEST_RESULT test() {
  __SCOPE_LOG__;
#ifdef __GNUC__
  pthread_t thread1, thread2;

  pthread_create(&thread1, 0, &functionCount1, 0);
  pthread_create(&thread2, 0, &functionCount2, 0);
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
#endif // __GNUC__
  RETURN_OK();
}

}  // namespace conditional_posix

#endif /* SRC_THREAD_CONDITIONAL_POSIX_H_ */
