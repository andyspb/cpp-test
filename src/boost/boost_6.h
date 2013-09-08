#ifndef _BOOST_6_H_
#define _BOOST_6_H_

#include <boost/thread.hpp>
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <iostream>

namespace boost_6 {
boost::recursive_mutex g_Mutex6;

void f1() {
  std::cout << "boost_6::f1 before lock\n";
  //boost::recursive_mutex::scoped_lock lock(g_Mutex6);
  std::cout << "return from f1()" << std::endl;
}

int test() {
  std::cout << "Test: boost_6 --->" << std::endl;
  boost::recursive_mutex::scoped_lock lock(g_Mutex6);
  std::cout << "after: boost::recursive_mutex::scoped_lock lock(g_Mutex6);" << std::endl;
  f1();
  std::cout << "<--- passed" << std::endl;
  return 1;
}
} // boost_6

#endif // _BOOST_6_H_
