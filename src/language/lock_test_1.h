#pragma once
#include <pthread.h>
namespace lock_test {
class CLock {
  public:
    CLock::CLock() {
      pthread_mutex_init(&mutex, 0);
    }
    CLock::~CLock() {
      pthread_mutex_destroy(&mutex);
    }
    void CLock::lock() {
      pthread_mutex_lock(&mutex);
    }

    int CLock::try_lock() {
      return pthread_mutex_trylock(&mutex);
    }

    void CLock::unlock() {
      pthread_mutex_unlock(&mutex);
    }

  private:
    //Non-assignable
    CLock(CLock&) ;
    CLock& operator=(const CLock&);
    pthread_mutex_t mutex;
};
}
