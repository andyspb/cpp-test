//  cpp0x_thread.h
//  author: andrey.krutogolov@gmail.com
//  date:   03.02.2013

#ifndef CPP0X_THREAD_H_
#define CPP0X_THREAD_H_

// #include <thread>
#include <iostream>
#include <boost/thread.hpp>

namespace cpp0x_thread {

void doSomeWork(void) {
  std::cout << "hello from thread..." << std::endl;
  return;
}

int test() {
  std::cout << "Test std::thread:------------->\n";

  boost::thread t(doSomeWork);
  t.join();

  return 1;
}

}  // namespace cpp0x_thread

#endif  // CPP0X_THREAD_H_
