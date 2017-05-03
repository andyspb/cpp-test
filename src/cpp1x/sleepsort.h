/*
 * sleepsort.h
 *
 *  Created on: May 3, 2017
 *      Author: andy
 */

#ifndef SRC_CPP1X_SLEEPSORT_H_
#define SRC_CPP1X_SLEEPSORT_H_

namespace sleepsort {

void sort(unsigned x) {
  std::this_thread::sleep_for(std::chrono::milliseconds(x));
  std::cout << x << " ";
}


TEST_RESULT test() {
  __SCOPE_LOG__;
  std::vector<unsigned> v = {1,20,5,8,33,4,22,3,99,12};
  size_t len= v.size();
  for (auto i : v) {
    std::cout << i << " ";
  }
  std::endl(std::cout);

  std::vector<std::thread> threads;
  for (size_t i = 0; i<len; ++i) {
    threads.push_back(std::thread(&sort, v[i]));
  }

  for(size_t i = 0; i<len; ++i) {
    threads[i].join();
  }

  std::endl(std::cout);
  RETURN_OK();
}


}  // namespace sleepsort



#endif /* SRC_CPP1X_SLEEPSORT_H_ */
