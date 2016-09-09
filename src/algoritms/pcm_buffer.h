/*
 * pcm_buffer.h
 *
 *  Created on: May 28, 2016
 *      Author: andy
 */

#ifndef SRC_ALGORITMS_PCM_BUFFER_H_
#define SRC_ALGORITMS_PCM_BUFFER_H_

#include <iostream>
#include <deque>

#include <memory>
//#include <mutex>
//#include <thread>
#include <functional>


#define DEFAULT_MAX 100

namespace pcm_buffer {
/*
struct PcmData {
  PcmData(): data(0), size(0) {}
  void* data;
  size_t size;
};

template<size_t size = DEFAULT_MAX>
class PcmBuffer {
  std::deque<PcmData> deque_;
  size_t size_;
  size_t max_size_;
  mutable std::mutex mutex_;
 public:
  PcmBuffer()
      : size_(0),
        max_size_(size) {
  }

  ~PcmBuffer() {
  }

  bool Empty() const {
    return deque_.empty();
  }

  bool Full() const {
    return deque_.size() == max_size_;
  }

  void Push(const PcmData& pcm_data) {
    std::lock_guard<std::mutex> lock(mutex);
    while (Full()) {
      deque_.pop_front();
    }
    deque_.push_back(pcm_data);
  }

  bool Pop(PcmData* pcm_data) {
    std::lock_guard<std::mutex> lock(mutex);
    if (Empty()) {
      return false;
    };
    *pcm_data = deque_.back();
    deque_.pop_back();
    return true;
  }
};

void thread_func_write(void* buffer) {
  PcmBuffer<DEFAULT_MAX>* pcm_buffer = reinterpret_cast<PcmBuffer<DEFAULT_MAX>*>(buffer);

  for (int i = 0; i <DEFAULT_MAX; ++i) {
    int data = i;
    PcmData pcm_data;
    pcm_data.data = static_cast<void*>(&data);
    pcm_buffer->Push(pcm_data);
    std::cout << "write:" <<data << " " << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
  }
}

void thread_func_read(void* buffer) {
  PcmBuffer<DEFAULT_MAX>* pcm_buffer = reinterpret_cast<PcmBuffer<DEFAULT_MAX>*>(buffer);
  for (int i = 0; i <DEFAULT_MAX; ++i) {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    PcmData pcm_data;
    if (pcm_buffer->Pop(&pcm_data) ) {
      int* data = static_cast<int*>(pcm_data.data);
      std::cout << "read:" << *data << " " << std::endl;
    }
  }
}

*/
// test
TEST_RESULT test() {
  __SCOPE_LOG__;

/*
  PcmBuffer<DEFAULT_MAX> pcm_buffer;

  PcmBuffer<DEFAULT_MAX> buffer;


  std::thread t1(thread_func_write, &buffer);
  std::thread t2(thread_func_read, &buffer);

  t1.join();
  t2.join();
*/
  RETURN_OK();
}
}  // namespace pcm_buffer

#endif /* SRC_ALGORITMS_PCM_BUFFER_H_ */
