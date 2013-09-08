#ifndef _BOOST_PC_2_H_
#define _BOOST_PC_2_H_

#include <iostream>
#include <deque>
#include <boost/thread.hpp>

namespace boost_pc_2 {
boost::mutex mutex_l;
std::deque<std::string> _deque;
void producer() {
  for (int i = 0; i < 20; i++) {
    {
      boost::lock_guard<boost::mutex> lock(mutex_l);
      std::stringstream st;
      st << i;
      std::string mystring = st.str();
      std::cout << "producer() pushing string onto queue "
          << std::string("test") + mystring << std::endl;
      _deque.push_back(std::string("test" + mystring));
      boost::this_thread::sleep(boost::posix_time::milliseconds(3));
    }
  }
}

void consumer() {
  for (int i = 0; i < 20; i++) {
    {
      boost::lock_guard<boost::mutex> lock(mutex_l);
      if (!_deque.empty()) {
        std::cout << "consumer() popped string " << _deque.front() << " from queue"
            << std::endl;
        _deque.pop_front();
      }
      boost::this_thread::sleep(boost::posix_time::milliseconds(3));
    }
  }
}

int test() {
  boost::thread producer_thread(producer);
  boost::thread consumer_thread(consumer);

  producer_thread.join();
  consumer_thread.join();

  return 1;
}
} // namespace boost_pc_2

#endif // _BOOST_PC_2_H_

