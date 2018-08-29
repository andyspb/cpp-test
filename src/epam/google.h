/*
 * google.h
 *
 *  Created on: 26 ���. 2015 �.
 *      Author: andy
 */

#ifndef GOOGLE_H_
#define GOOGLE_H_

#if _WIN32
// windows code goes here
typedef uint64_t uint;
#endif

#ifdef __GNUC__
#include <pthread.h>

#include <mutex>

namespace google_test {
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
//

struct ScopeLock {
  ScopeLock() {
//    pthread_mutex_lock (&mutex);  // lock
  }
  ~ScopeLock() {
//    pthread_mutex_unlock (&mutex);  // unlock
  }
};

// https://docs.google.com/document/d/1OaKufEI1JDjaKsUjQsSpjQY11UoTkPfYI7L3DBoxgqE/edit
// calculate operations on processor
// comp 3 Mh/s, 4 cores * 2 = 8 processes , no timers
// 3000000 * 8 = 24000000;

// global
volatile uint g_uid;
uint getId() {
  ScopeLock scopeLock;
  return ++g_uid;
}

struct Event {
  uint getAddress() {
    return 0;
  }
};

uint assignId(Event& ev) {
  uint id = (uint) ev.getAddress();
  return id;
}

}  // namespace google_test

#endif // __GNUC__
#endif /* GOOGLE_H_ */
