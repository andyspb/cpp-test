#ifndef _BOOST_TEST_3_H_
#define _BOOST_TEST_3_H_

#include <boost/thread.hpp>
#include <queue>
#include <iostream>

namespace boost_3 {
std::queue<int> int_que;
boost::mutex m_mutex;
void prod() {
  for (int i = 0; i < 20; i++) {
    {
      boost::lock_guard<boost::mutex> lock(m_mutex);
      std::cout << "producing ("/*<<boost::this_thread::get_id()*/<< ").. " << i
                << std::endl;
      int_que.push(i);
    }

    boost::this_thread::sleep(boost::posix_time::milliseconds(3));

  }

}

void cons() {
  for (int i = 0; i < 20; i++) {
    {
      boost::lock_guard<boost::mutex> lock(m_mutex);
      if (int_que.size() > 0) {
//        int v = int_que.front();
        int_que.pop();
        boost::thread::id id = boost::this_thread::get_id();
        std::cout << &id;
        std::cout << "consuming("/*<<boost::this_thread::get_id()*/<< ").. "
                  << i << std::endl;
      }
    }
    //boost::this_thread::yield();

    boost::this_thread::sleep(boost::posix_time::milliseconds(3));
  }
}

int test() {
  std::cout << "Test: boost_3 --->" << std::endl;
  boost::thread p(prod);
  boost::thread c(cons);
  p.join();
  c.join();
  std::cout << "<--- test passed" << std::endl;
  return 1;
}

}  // namespace boost_3

#endif // #define _BOOST_TEST_3_H_
