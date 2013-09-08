#ifndef _BOOST_LAMBDA_TEST_H_
#define _BOOST_LAMBDA_TEST_H_

#include <boost/lambda/lambda.hpp>
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

namespace boost_lambda {

int test() {
  std::cout << "Test: boost_lambda test --->" << std::endl;
  using namespace boost::lambda;
//  typedef std::istream_iterator<int> in;
//  std::for_each(in(std::cin), in(), std::cout << (_1 * 3) << " ");
  std::vector<int> vec;
  for (int i = 0; i<10; ++i) {
     vec.push_back(i);
  }
  std::for_each(vec.begin(), vec.end(),
      std::cout << boost::lambda::_1 << ":"<< (boost::lambda::_1 * 3) << " ");
  std::endl(std::cout);
  std::cout << "Test: boost_lambda test" << std::endl;
  return 1;
}
} // namespace boost_lambda_test

#endif  // _BOOST_LAMBDA_TEST_H_

