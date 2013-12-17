//  cpp0x_thread.h
//  author: andrey.krutogolov@gmail.com
//  date:   03.02.2013

#ifndef CPP0X_THREAD_H_
#define CPP0X_THREAD_H_

//#include <thread>
#include <iostream>

namespace cpp0x_thread {

using namespace std;

void doSomeWork(void) {
  cout << "hello from thread..." << endl;
  return;
}

int test() {
  cout << "Test std::thread:------------->\n";

//  thread t(doSomeWork);
//  t.join();

  return 1;
}

}  // namespace cpp0x_thread

#endif  // CPP0X_THREAD_H_
