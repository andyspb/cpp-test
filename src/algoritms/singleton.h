#pragma once
#ifdef __WIN32__
#include "stdafx.h"
#endif
namespace singleton {

using namespace std;

class ScopeLock {
 public:
  ScopeLock() {
    //       InitializeCriticalSection(&cs);
    Lock();
  }
  virtual ~ScopeLock() {
    //       DeleteCriticalSection(&cs);
    Unlock();
  }

 private:
  //     CRITICAL_SECTION cs;
  void Lock() {
    //       EnterCriticalSection(&cs);
  }
  void Unlock() {
    //       LeaveCriticalSection(&cs);
  }
};

//
// This version solves the problems of the minimalist Singleton above,
// but strictly speaking only in a single-threaded environment,
// and use in a multythreaded environment when relying on the ABI
// may still pose problems at program termination time.
//
class Singleton {
 private:
  Singleton() {
  }
  ~Singleton() {
  }
  Singleton(const Singleton &);             // intentionally undefined
  Singleton & operator=(const Singleton &);  // intentionally undefined

  static mutable Singleton * volatile _instance;

 public:
  static Singleton * getInstance();
  static ScopeLock lock;
};

Singleton* Singleton::_instance = 0;
ScopeLock Singleton::lock;

Singleton* Singleton::getInstance() {
  if (!_instance) {
    ScopeLock lock;
    if (!_instance) {
      Singleton* tmp = new Singleton();
      _instance = tmp;
    }
  }
  return _instance;
}

void func(void *);

void test() {
  printf("singleton pattern test\n");
//        HANDLE handles[2];
//        handles[0] = (HANDLE)_beginthread(func,0,0);
//        handles[1] = (HANDLE)_beginthread(func,0,0);
//
//        WaitForMultipleObjects(2,handles,1,-1);

  printf("\n");
}

void func(void *) {
  cout << "from func";
  Singleton * singl1 = Singleton::getInstance();
  printf("singl1=%p\n", singl1);
}

}
