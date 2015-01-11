#pragma once
#include "stdafx.h"
namespace singleton_with_muex {

using namespace std;

class MutexGuard {
  public:
    MutexGuard() {
      //          mutex = (HANDLE)CreateMutex(0,0,"MutexGuard");
    }
    virtual ~MutexGuard() {
      //        CloseHandle(mutex);
    }
    void Lock() {
      cout << "MutexGuard::Lock() called\n";
//            DWORD result = WaitForSingleObject(mutex,INFINITE);
//            cout<<"result="<<result<<"\n";
      cout << "MutexGuard::Lock() return\n";
    }
    void Unlock() {
      cout << "MutexGuard::Unlock() called\n";
//            ReleaseMutex(mutex);
      cout << "MutexGuard::Unlock() return\n";
    }

  private:
//        HANDLE mutex;
};

//
// This version solves the problems of the minimalist Singleton above,
// but strictly speaking only in a single-threaded environment,
// and use in a multy-threaded environment when relying on the ABI
// may still pose problems at program termination time.
//
class Singleton_with_mutex {
  private:
    Singleton_with_mutex() {
    }
    ~Singleton_with_mutex() {
    }
    Singleton_with_mutex(const Singleton_with_mutex &); // intentionally undefined
    Singleton_with_mutex & operator=(const Singleton_with_mutex &); // intentionally undefined

    static Singleton_with_mutex *_instance;

  public:
    static Singleton_with_mutex * getInstance();
    static MutexGuard guard;
};

Singleton_with_mutex* Singleton_with_mutex::_instance = 0;
MutexGuard Singleton_with_mutex::guard;

Singleton_with_mutex* Singleton_with_mutex::getInstance() {
  cout << "called Singleton_with_mutex::getInstance()\n";

  if (!_instance) {
    guard.Lock();
    if (!_instance) {
      Singleton_with_mutex* tmp = new Singleton_with_mutex();
      _instance = tmp;

    }
    guard.Unlock();
  }
  return _instance;
}

void func1(void *);

void test() {
  printf("singleton with a mutex pattern test\n");
//        HANDLE handles[2];
//        handles[0] = (HANDLE)_beginthread(func1,0,0);
//        handles[1] = (HANDLE)_beginthread(func1,0,0);
//
//        WaitForMultipleObjects(2,handles,1,INFINITE);
  printf("exit\n");
}

void func1(void *) {
  cout << "from func1()";
  Singleton_with_mutex * singl1 = Singleton_with_mutex::getInstance();
  printf("singl1=%p\n", singl1);
}
}
