/*
 * threads.h
 *
 *  Created on: 31 мая 2015 г.
 *      Author: andy
 */

#ifndef SRC_THREAD_THREADS_H_
#define SRC_THREAD_THREADS_H_

// thread example
#include <iostream>       // std::cout
#include <thread>         // std::thread

namespace threads {

void foo()
{
  std::cout<< "Run foo()" << std::endl;
}

void bar(int x)
{
  std::cout<< "Run bar("<<x<<")" << std::endl;
}

int test()
{
  std::thread empty;
  std::thread first (foo);     // spawn new thread that calls foo()
  std::thread second (bar,0);  // spawn new thread that calls bar(0)

  std::cout << "main, foo and bar now execute concurrently...\n";

  // synchronize threads:
  first.join();                // pauses until first finishes
  second.join();               // pauses until second finishes

  std::cout << "foo and bar completed.\n";

  return 1;
}

}

#endif /* SRC_THREAD_THREADS_H_ */
