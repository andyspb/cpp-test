#ifndef _BOOST_PROD_CONS_H_
#define _BOOST_PROD_CONS_H_

#include <iostream>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition_variable.hpp>
#include <boost/thread/thread.hpp>
#include <queue>

namespace boost_prod_cons {

typedef boost::mutex::scoped_lock scoped_lock;
boost::mutex b_mutex;
boost::mutex __io_mutex;
boost::condition_variable b_empty;
boost::condition_variable b_full;
boost::condition_variable b_cond;

const int maxBufferSize = 3;
const int DataLength = 20;

struct Data {
    void addToBuffer(int i);
    int getFromBuffer();
    std::queue<int> buffer;
    bool stop;
    int counter;
};

class Producer {
  public:
    Producer() {
      std::cout << "producer ctor" << std::endl;
    }
    ~Producer() {
    }
    void run();
};

class Consumer {
  public:
    Consumer() {
      std::cout << "consumer ctor" << std::endl;
    }
    ~Consumer() {
    }
    void run();
};

Data data;

void Producer::run() {
  std::cout << "Producer >>>\n" << std::endl;
  data.stop = false;
  data.counter = 1;
  for (int i = 0; i < DataLength; i++) {
    {
      scoped_lock lock(b_mutex);
      data.addToBuffer(i);
      std::cout << i << "\tProducer" << std::endl;
      if (data.counter == DataLength) {
        data.stop = true;
      }
      if ((int)data.buffer.size() == maxBufferSize || data.stop) {
        std::cout << "buffer full:" << data.buffer.size() << std::endl;
        b_full.notify_one();
        if (!data.stop) {
          b_empty.wait(lock);
        }
      }

    }
  }
  std::cout << "Producer <<<\n" << std::endl;
}

void Consumer::run() {
  std::cout << "Consumer >>>\n" << std::endl;
  while (true) {
    scoped_lock lock(b_mutex);
    if (data.buffer.size() == 0)
      b_full.wait(lock);
    while (data.buffer.size() > 0) {
      int value = data.getFromBuffer();
      std::cout << "\t" << value << "\tConsumer" << std::endl;
    }
    std::cout << "Buffer is empty:" << data.buffer.size() << std::endl;
    b_empty.notify_one();
    if (data.stop) {
      break;
    }
  }
  std::cout << "Consumer <<<\n" << std::endl;
}

void Data::addToBuffer(int i) {
  scoped_lock lock(__io_mutex);
  buffer.push(i);
  ++counter;
}

int Data::getFromBuffer() {
  scoped_lock lock(__io_mutex);
  int i = buffer.front();
  buffer.pop();
  return i;
}

int test() {
  std::cout << "Test: boost producer consumer test --->" << std::endl;
  Producer producer;
  Consumer consumer;
  boost::thread prod_thread(&Producer::run, &producer);
  boost::thread cons_thread(&Consumer::run, &consumer);

  prod_thread.join();
  cons_thread.join();

  std::cout << "<--- passed" << std::endl;
  return 1;
}
} // namespace boost_prod_cons

#endif // _BOOST_PROD_CONS_H_
