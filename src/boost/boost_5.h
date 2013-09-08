#ifndef _BOOST_5_H_
#define _BOOST_5_H_

#include <boost/thread.hpp>
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <iostream>

namespace boost_5 {
boost::mutex g_Mutex;

void test_reentrant() {
  std::cout << "Before reeentrant lock" << std::endl;
  boost::mutex::scoped_lock lock(g_Mutex);
  std::cout << "exit" << std::endl;
}

int test() {
  std::cout << "Test: test reentrant boost::mutex --->" << std::endl;
  boost::mutex::scoped_lock lock(g_Mutex);
  // bost lock is not recursive
  // test_reentrant();
  std::cout << "<--- test passed" << std::endl;
  return 1;
}

} // namespace boost_5

#endif // _BOOST_5_H_
