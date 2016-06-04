/*
 * circular_buffer.h
 *
 *  Created on: Jun 3, 2016
 *      Author: andy
 */

#ifndef SRC_CPP1X_RING_BUFFER_LOCKED_H_
#define SRC_CPP1X_RING_BUFFER_LOCKED_H_

#include <iostream>
#include <thread>
#include <deque>
#include <mutex>
#include <chrono>
#include <condition_variable>

namespace ring_buffer_locked {

//using std::deque;

class Buffer {
 public:
  void add(int num) {
    while (true) {
      std::unique_lock<std::mutex> locker(mutex_);
      cond_.wait(locker, [this]() {return buffer_.size() < size_;});
      buffer_.push_back(num);
      locker.unlock();
      cond_.notify_all();
      return;
    }
  }
  int remove() {
    while (true) {
      std::unique_lock<std::mutex> locker(mutex_);
      cond_.wait(locker, [this]() {return buffer_.size() > 0;});
      int back = buffer_.back();
      buffer_.pop_back();
      locker.unlock();
      cond_.notify_all();
      return back;
    }
  }
  Buffer() {
  }
 private:
  std::deque<int> buffer_;
  const unsigned int size_ = 100;
  std::mutex mutex_;

public:
  std::mutex cout_mutex_;
  std::condition_variable cond_;


};

class Producer {
 public:
  Producer(Buffer* buffer)
      : buffer_(buffer) {
  }
  void run() {
    while (true) {
      int num = std::rand() % 100;
      buffer_->add(num);
      buffer_->cout_mutex_.lock();
      std::cout << "Produced: " << num << std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(50));
      buffer_->cout_mutex_.unlock();
    }
  }
 private:
  Buffer *buffer_;
};

class Consumer {
 public:
  Consumer(Buffer* buffer)
      : buffer_(buffer) {
  }
  void run() {
    while (true) {
      int num = buffer_->remove();
      buffer_->cout_mutex_.lock();
      std::cout << "\t\tConsumed: " << num << std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(50));
      buffer_->cout_mutex_.unlock();
    }
  }
 private:
  Buffer *buffer_;
};

TEST_RESULT test() {
  __SCOPE_LOG__;
  Buffer b;
  Producer p(&b);
  Consumer c(&b);

  std::thread producer_thread(&Producer::run, &p);
  std::thread consumer_thread(&Consumer::run, &c);

  producer_thread.join();
  consumer_thread.join();
  RETURN_OK();
}

}  // namespace circular_buffer

#endif /* SRC_CPP1X_RING_BUFFER_LOCKED_H_ */
