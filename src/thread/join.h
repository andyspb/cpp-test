/*
 * join.h
 *
 *  Created on: Aug 20, 2015
 *      Author: andy
 */

#ifndef SRC_THREAD_JOIN_H_
#define SRC_THREAD_JOIN_H_

#include <thread>

namespace join {

void foo() {
  LOG(INFO) << "Run foo()";
}

void bar(int x) {
  LOG(INFO) << "Run bar(" << x << ")";
}

TEST_RESULT test() {

  LOG(INFO) << __PRETTY_FUNCTION__;

  std::thread empty;
  std::thread first(foo);     // spawn new thread that calls foo()
  std::thread second(bar, 0);  // spawn new thread that calls bar(0)

  std::cout << "main, foo and bar now execute concurrently...\n";

  // synchronize threads:
  first.join();                // pauses until first finishes
  second.join();               // pauses until second finishes

  std::cout << "foo and bar completed.\n";

  RETURN_OK();
}

}  // namespace join

#endif /* SRC_THREAD_JOIN_H_ */
