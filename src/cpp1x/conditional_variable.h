/*
 * conditional_variable.h
 *
 *  Created on: Jul 11, 2016
 *      Author: andy
 */

#ifndef SRC_CPP1X_CONDITIONAL_VARIABLE_H_
#define SRC_CPP1X_CONDITIONAL_VARIABLE_H_

#include <condition_variable>
#include <mutex>
#include <thread>
#include <iostream>
#include <queue>
#include <chrono>

namespace conditional_variable_ {

TEST_RESULT test() {
  __SCOPE_LOG__;

  std::queue<int> produced_nums;
  std::mutex m;
  std::condition_variable cond_var;
  bool done = false;
  bool notified = false;

  std::thread producer([&]() {
    for (int i = 0; i < 5; ++i) {
      std::this_thread::sleep_for(std::chrono::seconds(1));
      std::unique_lock<std::mutex> lock(m);
      std::cout << "producing " << i << '\n';
      produced_nums.push(i);
      notified = true;
      cond_var.notify_one();
    }

    done = true;
    cond_var.notify_one();
  });

  std::thread consumer([&]() {
    std::unique_lock<std::mutex> lock(m);
    while (!done) {
      while (!notified) {  // loop to avoid spurious wakeups
        cond_var.wait(lock);
      }
      while (!produced_nums.empty()) {
        std::cout << "consuming " << produced_nums.front() << '\n';
        produced_nums.pop();
      }
      notified = false;
    }
  });

  producer.join();
  consumer.join();

  RETURN_OK();
}

}  // namespace conditional_variable

#endif /* SRC_CPP1X_CONDITIONAL_VARIABLE_H_ */
