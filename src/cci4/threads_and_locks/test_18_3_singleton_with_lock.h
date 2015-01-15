/*
 * test_18_3_singleton_with_lock.h
 *
 *  Created on: 13.11.2012
 *      Author: andy
 */

#ifndef TEST_18_3_SINGLETON_WITH_LOCK_H_
#define TEST_18_3_SINGLETON_WITH_LOCK_H_

#include <iostream>

using namespace std;

namespace test_18_3_singleton_with_lock {

class A {
};

/* Place holder for thread synchronization lock */
class Lock {
 public:
  Lock() { /* placeholder code to create the lock */
  }
  ~Lock() { /* placeholder code to deallocate the lock */
  }
  void AcquireLock() { /* placeholder to acquire the lock */
  }
  void ReleaseLock() { /* placeholder to release the lock */
  }
};

/* Singleton class with a method that creates a new instance of the
 * class of the type of the passed in template if it does not
 * already exist. */
template<class T>
class Singleton {
 private:
  static Lock lock;
  static T* object;
 protected:
  Singleton() {
  }

 public:
  static T * Instance() {
    /* if object is not initialized, acquire lock */
    if (object == 0) {
      lock.AcquireLock();
      /* If two threads simultaneously check and pass the first “if”
       * condition, then only the one who acquired the lock first
       * should create the instance */
      if (object == 0) {
        object = new T;
      }
      lock.ReleaseLock();
    }
    return object;
  }
};

template<class T>
T *Singleton<T>::object = NULL;

template<class T>
Lock Singleton<T>::lock;

int test() {
  std::cout << __PRETTY_FUNCTION__ << std::endl;

#pragma GCC diagnostic ignored "-Wunused-variable"
  A* singleton = Singleton<A>::Instance();
  return 1;
}
}  // test_18_3_singleton_with_lock

#endif /* TEST_18_3_SINGLETON_WITH_LOCK_H_ */
