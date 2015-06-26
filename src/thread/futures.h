/*
 * futures.h
 *
 *  Created on: 31 мая 2015 г.
 *      Author: andy
 */

#ifndef SRC_THREAD_FUTURES_H_
#define SRC_THREAD_FUTURES_H_


// future example
#include <iostream>       // std::cout
#include <future>         // std::async, std::future
#include <chrono>         // std::chrono::milliseconds

#include <utility>      // std::move
#include <iostream>     // std::cout
#include <vector>       // std::vector
#include <string>       // std::string

namespace futures {

// a non-optimized way of checking for prime numbers:
bool is_prime (int x) {
  for (int i=2; i<x; ++i) if (x%i==0) return false;
  return true;
}

int test ()
{
  // call function asynchronously:
  std::future<bool> fut = std::async (is_prime,444444443);

  // do something while waiting for function to set future:
//  std::cout << "checking, please wait";
//  std::chrono::milliseconds span (10);
//  while (fut.wait_for(span)==std::future_status::timeout)
//    std::cout << '.' << std::flush;
//
//  bool x = fut.get();     // retrieve return value
//
//  std::cout << "\n444444443 " << (x?"is":"is not") << " prime.\n";


  std::string foo = "foo-string";
  std::string bar = "bar-string";

  std::cout << "bar:" << bar << "\n";

  std::vector<std::string> myvector;

  myvector.push_back(foo);                    // copies
  myvector.push_back(std::move(bar));         // moves

  std::cout << "myvector contains:";
  for (std::string& x : myvector)
    std::cout << ' ' << x;
  std::cout << '\n';

  std::cout << "bar:" << bar << "\n";

  return 1;
}

}


#endif /* SRC_THREAD_FUTURES_H_ */
