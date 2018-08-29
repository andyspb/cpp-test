/*
 * deadlock.h
 *
 *  Created on: Aug 20, 2015
 *      Author: andy
 */

#ifndef SRC_THREAD_DEADLOCK_H_
#define SRC_THREAD_DEADLOCK_H_

#include <thread>
#include <mutex>
#include <chrono>

std::mutex m1, m2;
volatile int v1(0), v2(0);

namespace deadlock {

class Lock {
 public:
  Lock(std::mutex& m1, std::mutex& m2)
      : m1_(m1),
        m2_(m2) {
    m1_.lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    m2_.lock();
  }
  virtual ~Lock() {
    m2_.unlock();
    m1_.unlock();
  }
 private:
  std::mutex& m1_;
  std::mutex& m2_;
};

void foo() {
  __SCOPE_LOG__;
  Lock(m1, m2);
//  LOG(INFO) << "v1:" << v1;
//  while (!v2) {
//  }
//  LOG(INFO) << "v2:" << v2;
}

void bar(int x) {
  __SCOPE_LOG__;
  Lock(m2, m1);
//  v2 = 1;
//  LOG(INFO) << "v2:" << v2;
//  while (!v1) {
//  }
//  LOG(INFO) << "v1:" << v1;
}

void foo1() {
  LOG(INFO) << "foo1() >>> ";
  std::lock(m2, m1);
  LOG(INFO) << "<<< foo1()";
  m1.unlock();
  m2.unlock();
}

void bar1(int x) {
  LOG(INFO) << "bar1(" << x << ") >>>";
  std::lock(m1, m2);
  LOG(INFO) << "<<< bar1(" << x << ")";
  m2.unlock();
  m1.unlock();
}

TEST_RESULT test() {

  std::thread t1(foo);
  std::thread t2(bar, 1);
//  std::thread t2(bar1, 1);

  t1.join();
  t2.join();

  RETURN_OK();
}

}  // namespace deadlock

#endif /* SRC_THREAD_DEADLOCK_H_ */
