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

std::mutex m1, m2;
volatile int v1(0), v2(0);


namespace deadlock {

void foo() {
  LOG(INFO) << "foo() >>> ";
  m1.lock();
  v1 = 1;
  LOG(INFO) << "v1:" << v1;
  while (!v2) {
  }
  LOG(INFO) << "v2:" << v2;
  m2.lock();
  LOG(INFO) << "<<< foo()";
}

void bar(int x) {
  LOG(INFO) << "bar(" << x << ") >>>";
  m2.lock();
  v2 = 1;
  LOG(INFO) << "v2:" << v2;
  while (!v1) {
  }
  LOG(INFO) << "v1:" << v1;
  m1.lock();
  LOG(INFO) << "<<< bar(" << x << ")";
}


TEST_RESULT test() {

  std::thread t1(foo);
  std::thread t2(bar,1);

  t1.join();
  t2.join();

  RETURN_OK();
}

}  // namespace deadlock

#endif /* SRC_THREAD_DEADLOCK_H_ */
