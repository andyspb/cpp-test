#ifndef _BOOST_TEST_2_H_
#define _BOOST_TEST_2_H_

#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition.hpp>
#include <iostream>

namespace boost_2 {

const int BUF_SIZE = 5;
const int ITERS = 30;

static boost::mutex _io_mutex;

class _buffer {
  public:
    typedef boost::mutex::scoped_lock scoped_lock;

    _buffer()
        : p(0), c(0), full(0) {
    }

    void put(int m) {
      scoped_lock lock(mutex);
      if ((int) full == BUF_SIZE) {
        {
          boost::mutex::scoped_lock lock(_io_mutex);
          std::cout << "Buffer is full. " << full << " Waiting..." << std::endl;
        }
        while ((int) full == BUF_SIZE)
          cond.wait(lock);
      }
      buf[p] = m;
      p = (p + 1) % BUF_SIZE;
      ++full;
      cond.notify_one();
    }

    int get() {
      scoped_lock lk(mutex);
      if (full == 0) {
        {
          boost::mutex::scoped_lock lock(_io_mutex);
          std::cout << "Buffer is empty. " << full << " Waiting..."
              << std::endl;
        }
        while (full == 0)
          cond.wait(lk);
      }
      int i = buf[c];
      c = (c + 1) % BUF_SIZE;
      --full;
      cond.notify_one();
      return i;
    }

  private:
    boost::mutex mutex;
    boost::condition cond;
    unsigned int p, c, full;
    int buf[BUF_SIZE];
};

_buffer buf;

void writer() {
  for (int n = 0; n < ITERS; ++n) {
    {
      boost::mutex::scoped_lock lock(_io_mutex);
      std::cout << "sending: " << n << std::endl;
    }
    buf.put(n);
  }
}

void reader() {
  for (int x = 0; x < ITERS; ++x) {
    int n = buf.get();
    {
      boost::mutex::scoped_lock lock(_io_mutex);
      std::cout << "received: " << n << std::endl;
    }
  }
}

int test() {
  std::cout << "Test: boost_2 --->" << std::endl;
  boost::thread thrd1(&reader);
  boost::thread thrd2(&writer);
  thrd1.join();
  thrd2.join();
  std::cout << "<--- test passed" << std::endl;
  return 1;
}

} // namespace boost_2

#endif // _BOOST_TEST_2_H_
