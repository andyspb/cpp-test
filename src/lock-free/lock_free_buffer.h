/*
 * lock_free_buffer.h
 *
 *  Created on: May 30, 2016
 *      Author: andy
 */

#ifndef SRC_LOCK_FREE_LOCK_FREE_BUFFER_H_
#define SRC_LOCK_FREE_LOCK_FREE_BUFFER_H_

#include <atomic>
#include <chrono>
#include <iostream>
#include <thread>

#define MAX_SIZE 100
#define READ_SLEEP   100
#define WRITE_SLEEP  500

//std::atomic_flag static_flag = ATOMIC_FLAG_INIT;

namespace lock_free_buffer {

struct PcmData {
  PcmData()
      : data_(0),
        size_(-1) {
  }
  PcmData(void* data, int size)
      : data_(data),
        size_(size) {
  }
  PcmData(int* data, int size)
      : data_(static_cast<void*>(data)),
        size_(size) {
  }
  PcmData(char* data, int size)
      : data_(static_cast<void*>(data)),
        size_(size) {
  }
  void* data_;
  int size_;
};

template<size_t size = DEFAULT_MAX>
class LockFreeBuffer {
  const size_t max_size_ = size;
  enum {
    Capacity = MAX_SIZE + 1
  };

 public:
  LockFreeBuffer()
      : tail_(0),
        head_(0) {
  }

  virtual ~LockFreeBuffer() {
  }

  bool Push(const PcmData& pcm_data) {
    auto current_tail = tail_.load();
    auto next_tail = increment(current_tail);
    if (next_tail == head_.load()) {
      head_.store(increment(head_));
    }
    array_[current_tail] = pcm_data;
    tail_.store(next_tail);
    return true;
//    if (next_tail != head_.load()) {
//      array_[current_tail] = pcm_data;
//      tail_.store(next_tail);
//      return true;
//    }
//    std::cout << __FUNCTION__ << " full" << "\n";
//    return false;  // full queue
  }

  bool Pop(PcmData& pcm_data) {
    const auto current_head = head_.load();
    std::cout << "\t" << __FUNCTION__ << " current_head:" << current_head
              << " tail_.load()=" << tail_.load() << "\n";
    if (current_head == tail_.load()) {
      pcm_data.data_ = 0;
      pcm_data.size_ = -1;
      return false;   // empty queue
    }

    pcm_data = array_[current_head];
    head_.store(increment(current_head));
    return true;
  }

  bool Empty() const {
    return (head_.load() == tail_.load());
  }
  bool Full() const {
    const auto next_tail = increment(tail_.load());
    return (next_tail == head_.load());
  }

//  bool isLockFree() const {
//    return static_flag.;
//  }

  size_t increment(size_t index) const {
    return (index + 1) % Capacity;
  }

 private:
  std::atomic<size_t> tail_;
  std::atomic<size_t> head_;
  PcmData array_[Capacity];

};

void thread_write(void* buffer) {
  LockFreeBuffer<MAX_SIZE>* pcm_buffer = reinterpret_cast<LockFreeBuffer<
      MAX_SIZE>*>(buffer);

  for (int i = 0; i < DEFAULT_MAX; ++i) {
    std::this_thread::sleep_for(std::chrono::milliseconds(WRITE_SLEEP));
    int data = i;
    PcmData pcm_data;
    pcm_data.data_ = static_cast<void*>(&data);
    pcm_buffer->Push(pcm_data);
    std::cout << __FUNCTION__ << "write:" << data << " " << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
  }
}

void thread_read(void* buffer) {
  LockFreeBuffer<MAX_SIZE>* pcm_buffer = reinterpret_cast<LockFreeBuffer<
      MAX_SIZE>*>(buffer);
  for (int i = 0; i < DEFAULT_MAX; ++i) {
    std::this_thread::sleep_for(std::chrono::milliseconds(READ_SLEEP));
    PcmData pcm_data;
    if (pcm_buffer->Pop(pcm_data)) {
      int* data = static_cast<int*>(pcm_data.data_);
      if (data) {
        std::cout << "\t\t" << __FUNCTION__ << " read: " << "data_:" << *data
                  << " " << std::endl;
      } else {
        std::cout << "\t\t" << __FUNCTION__ << " read: " << "empty"
                  << std::endl;
      }
    }
  }
}

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__ << " >>>";

  LockFreeBuffer<MAX_SIZE> buff;

  std::thread t1(thread_write, &buff);
  std::thread t2(thread_read, &buff);

  t1.join();
  t2.join();

  LOG(INFO) << __PRETTY_FUNCTION__ << " <<<";
  RETURN_OK();
}

}  // namespace lock_free_buffer

#endif /* SRC_LOCK_FREE_LOCK_FREE_BUFFER_H_ */
