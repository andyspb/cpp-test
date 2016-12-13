//  cpp0x_thread.h
//  author: andrey.krutogolov@gmail.com
//  date:   03.02.2013

#ifndef CPP0X_THREAD_H_
#define CPP0X_THREAD_H_

#include <thread>
#include <iostream>

namespace threads {

void func(void) {
  LOG(INFO) << " hello from thread...";
  return;
}

TEST_RESULT test() {
  __SCOPE_LOG__;
  LOG(INFO) << "Test std::thread:------------->\n";

  std::thread t(func);
  t.join();

  RETURN_OK();
}

}  // namespace cpp0x_thread

#endif  // CPP0X_THREAD_H_
