#ifndef _BOOST_7_H_
#define _BOOST_7_H_

#include <boost/thread.hpp>
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <iostream>

namespace boost_7 {
boost::mutex mutex_7;

void f1_7() {
  std::cout << "boost_7::f1 before lock\n";
  //boost::lock_guard<boost::mutex> lock_g(mutex_7);
  std::cout << "1\n";
}

int test() {
  std::cout << "Test: boost_4 --->" << std::endl;
  boost::lock_guard<boost::mutex> lock_g(mutex_7);
  std::cout << "after:  boost::lock_guard<boost::mutex> lock_g(mutex_7);" << std::endl;
  f1_7();
  std::cout << "<--- test passed" << std::endl;
  return 1;
}
} // namespace boost_7

#endif // _BOOST_7_H_
