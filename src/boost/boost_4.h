#ifndef _BOOST_4_H_
#define _BOOST_4_H_

#include <iostream>
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>

namespace boost_4 {

static boost::mutex io_mutex_;

struct _count {
    _count(int id)
        : id(id) {
    }
    void operator()() {
      for (int i = 0; i < 10; ++i) {
        boost::this_thread::sleep(boost::posix_time::milliseconds(3));
        boost::mutex::scoped_lock lock(io_mutex_);
        std::cout << id << ": " << i << " ";
      }
      std::endl(std::cout);
    }
    int id;
};

int test() {
  std::cout << "Test: boost_4 --->" << std::endl;
  boost::thread thrd1(_count(1));
  boost::thread thrd2(_count(2));
  thrd1.join();
  thrd2.join();
  std::cout << "<--- passed" << std::endl;
  return 1;
}

}  // namespace boost_4

#endif  // _BOOST_4_H_
