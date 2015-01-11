/*
 * 13_11_circular_que.h
 *
 *  Created on: 06 џэт. 2015 у.
 *      Author: andy
 */

#ifndef _CIRCULAR_QUE_H_
#define _CIRCULAR_QUE_H_

namespace circular_que {

template<typename T>
class CircularQue {
 private:
  enum {
    default_max = 10
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
      throw "CQue empty";
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


int test() {
  return 1;
}

}  // namespace circular_que

#endif /* _CIRCULAR_QUE_H_ */
