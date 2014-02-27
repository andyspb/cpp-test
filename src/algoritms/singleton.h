#pragma once
#include "stdafx.h"
namespace singleton {

using namespace std;

class Guard {
  public:
    Guard() {
      //       InitializeCriticalSection(&cs);
    }
    virtual ~Guard() {
      //       DeleteCriticalSection(&cs);
    }
    void Lock() {
      //       EnterCriticalSection(&cs);
    }
    void Unlock() {
      //       LeaveCriticalSection(&cs);
    }

  private:
    //     CRITICAL_SECTION cs;
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
    Singleton & operator=(const Singleton &); // intentionally undefined

    static mutable Singleton *_instance;

  public:
    static Singleton * getInstance();
    static Guard guard;
};

Singleton* Singleton::_instance = 0;
Guard Singleton::guard;

Singleton* Singleton::getInstance() {
  if (!_instance) {
    guard.Lock();
    if (!_instance) {
      _instance = new Singleton();
      //         Sleep(1000);
    }
  }
  guard.Unlock();
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
