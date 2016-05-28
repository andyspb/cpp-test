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
#include <mutex>

#define DEFAULT_MAX 100

namespace pcm_buffer {

class PcmData {
  void* data;
  size_t size;
};

template<size_t size = DEFAULT_MAX>
class PcmBuffer {
  std::deque<PcmData> deque_;
  size_t size_;
  size_t max_size_;
  std::mutex mutex_;
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

// test
TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;
  PcmBuffer<DEFAULT_MAX> pcm_buffer;
  RETURN_OK();
}
}  // namespace pcm_buffer

#endif /* SRC_ALGORITMS_PCM_BUFFER_H_ */
