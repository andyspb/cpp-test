/*
 * sleepsort_lambda.h
 *
 *  Created on: May 4, 2017
 *      Author: andy
 */

#ifndef SRC_CPP1X_SLEEPSORT_LAMBDA_H_
#define SRC_CPP1X_SLEEPSORT_LAMBDA_H_

namespace sleepsort_lambda {

template<class A>
void print_vec(std::vector<A>& vec) {
  size_t len= vec.size();
  for (const auto i : vec) {
    std::cout << i << " ";
  }
  std::endl(std::cout);
}


TEST_RESULT test() {
  __SCOPE_LOG__;
  std::vector<unsigned> vec = {1,20,5,8,33,4,22,3,99,12};
  print_vec(v);

  std::vector<std::thread> threads;
  for (const auto& v : vec) {
    threads.push_back(std::thread(([](unsigned x){
      std::this_thread::sleep_for(std::chrono::milliseconds(x));
      std::cout << x << " ";
    }), v));
  }

  for(size_t i = 0; i<vec.size(); ++i) {
    threads[i].join();
  }

  std::endl(std::cout);



  RETURN_OK();
}

}  // namespace sleepsort_lambda



#endif /* SRC_CPP1X_SLEEPSORT_LAMBDA_H_ */
