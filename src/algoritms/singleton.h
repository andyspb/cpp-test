#ifndef __SINGLETON_H
#define __SINGLETON_H

#include <mutex>
#include <thread>
#include <iostream>
#include <chrono>

namespace singleton {

static std::mutex mutex_;

class ScopeLock {
 public:
  ScopeLock() {
    std::lock_guard<std::mutex> lock(mutex_);
  }
  virtual ~ScopeLock() {
    std::lock_guard<std::mutex> unlock(mutex_);
  }
};

class Singleton {
 public:
  static Singleton * getInstance();
  static ScopeLock lock;

 private:
  Singleton() {
  }
  ~Singleton() {
  }
  Singleton(const Singleton &);              // intentionally undefined
  Singleton & operator=(const Singleton &);  // intentionally undefined

  static Singleton * volatile _instance;
};

Singleton* volatile Singleton::_instance = 0;
ScopeLock Singleton::lock;

Singleton* Singleton::getInstance() {
//  if (!_instance) {
//    ScopeLock lock;
  if (!_instance) {
    Singleton* tmp = new Singleton();
    _instance = tmp;
  }
//  }
  return _instance;
}

void func();

TEST_RESULT test() {
  __SCOPE_LOG__;
  printf("singleton pattern test\n");

  std::thread t1(func);
  std::thread t2(func);
  printf("\n");
  RETURN_OK();
}

void func() {
  __SCOPE_LOG__;
  LOG(INFO) << "from func";
  std::this_thread::sleep_for(std::chrono::milliseconds(10));
  Singleton * singleton = Singleton::getInstance();
  printf("singl1=%p\n", singleton);
}

}  // singleton
#endif // #ifndef __SINGLETON_H
