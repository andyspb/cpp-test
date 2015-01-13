#ifndef _COMMON_CIRCULAR_QUE_H_
#define _COMMON_CIRCULAR_QUE_H_

#include <iostream>

template<typename T>
class CircularQue {
 private:
  enum {
    default_max = 100
  };
  size_t head_;
  size_t tail_;
  size_t size_;
  size_t capacity_;
  T * data_;
 public:
  CircularQue(size_t max_size = default_max)
      : head_(0),
        tail_(0),
        size_(0),
        capacity_(max_size),
        data_(new T[capacity_]) {
  }

  ~CircularQue() {
    delete[] data_;
  }

  size_t Size() const {
    return size_;
  }
  size_t Capacity() const {
    return capacity_;
  }
  bool IsEmpty() const {
    return size_ == 0;
  }
  bool IsFull() {
    return size_ == capacity_;
  }

  T Top() const {
    if (IsEmpty()) {
      throw "empty";
    }
    return data_[head_];
  }

  void Push(const T& val) {
    if (IsFull()) {
      std::cout << " CQue is full ...";
      return;
    }
    data_[tail_] = val;
    tail_ = (tail_ + 1) % capacity_;
    ++size_;
  }
  T Pop() {
    if (IsEmpty()) {
      throw "empty";
    };
    T tmp = data_[head_];
    head_ = (head_ + 1) % capacity_;
    --size_;
    return tmp;
  }
};

#endif /* _COMMON_CIRCULAR_QUE_H_ */
