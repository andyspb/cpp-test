#ifndef _BOOST_TEST1_H
#define _BOOST_TEST1_H

#include <boost/thread/mutex.hpp>
#include <boost/thread/thread.hpp>
#include <iostream>

namespace boost_threads {
static boost::mutex io_mutex;  // The iostreams are not guaranteed to be thread-safe!
class counter {
 public:
  counter()
      : count(0) {
  }
  int increment() {
    boost::mutex::scoped_lock scoped_lock(mutex);
    return ++count;
  }
 private:
  boost::mutex mutex;
  int count;
};

counter c;

void change_count() {
  int i = c.increment();
  boost::mutex::scoped_lock scoped_lock(io_mutex);
  std::cout << "count == " << i << std::endl;
}

int test() {
  std::cout << "Test: boost_1 --->" << std::endl;
  const int num_threads = 4;
  boost::thread_group threads;
  for (int i = 0; i < num_threads; ++i)
    threads.create_thread(&change_count);
  threads.join_all();
  std::cout << "<--- passed" << std::endl;
  return 1;
}
}  // namespace boost_1

#endif //  _BOOST_TEST1_H
