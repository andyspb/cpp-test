#ifndef _BOOST_COND_H_
#define _BOOST_COND_H_

#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition.hpp>
#include <iostream>

namespace boost_cond {
const unsigned int BUF_SIZE_COND = 10;
const unsigned int ITERS_COND = 100;
typedef boost::mutex::scoped_lock scoped_lock;

boost::mutex io_mutex_cond;

class buffer_cond {
  public:
    buffer_cond() : p(0), c(0), full(0) { }
    void put(int m) {
      scoped_lock lock(mutex);
      if (full == BUF_SIZE_COND) {
        {
          scoped_lock lock(io_mutex_cond);
          std::cout << "Buffer is full. Waiting..." << std::endl;
        }
        while (full == BUF_SIZE_COND)
          cond.wait(lock);
      }
      buf[p] = m;
      p = (p + 1) % BUF_SIZE_COND;
      ++full;
      cond.notify_one();
    }

    int get() {
      scoped_lock lk(mutex);
      if (full == 0) {
        {
          scoped_lock lock(io_mutex_cond);
          std::cout << "Buffer is empty. Waiting..." << std::endl;
        }
        while (full == 0)
          cond.wait(lk);
      }
      int i = buf[c];
      c = (c + 1) % BUF_SIZE_COND;
      --full;
      cond.notify_one();
      return i;
    }

  private:
    boost::mutex mutex;
    boost::condition cond;
    unsigned int p, c, full;
    int buf[BUF_SIZE_COND];
};

buffer_cond buf_cond;

void writer_cond() {
  for (unsigned int n = 0; n < ITERS_COND; ++n) {
    {
      scoped_lock lock(io_mutex_cond);
      std::cout << "sending: " << n << std::endl;
    }
    buf_cond.put(n);
  }
}

void reader_cond() {
  for (unsigned int x = 0; x < ITERS_COND; ++x) {
    int n = buf_cond.get();
    {
      scoped_lock lock(io_mutex_cond);
      std::cout << "received: " << n << std::endl;
    }
  }
}

int test() {
  boost::thread thrd1(&reader_cond);
  boost::thread thrd2(&writer_cond);
  thrd1.join();
  thrd2.join();
  return 1;
}
} // namespace boost_cond
#endif  // _BOOST_COND_H_
