#ifndef CIRCULAR_QUE_H__
#define CIRCULAR_QUE_H__

#include <iostream>

namespace circular_que {
template<typename T>
class CQue {
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
  CQue(size_t max_size = default_max)
      : head_(0),
        tail_(0),
        size_(0),
        capacity_(max_size),
        data_(new T[capacity_]) {
  }

  ~CQue() {
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

int test() {
  std::cout << "\tTest: circular que --->" << std::endl;
  CQue<int> cque(6);
  std::cout << "\tCQue capacity: " << cque.Capacity() << std::endl;
  std::cout << "\tPush: ";
  for (int i = 1; i < 20; ++i) {
    cque.Push(i);
    std::cout << i << ' ';
  }
  std::endl(std::cout);
  std::cout << "\tCQue size: " << cque.Size() << std::endl;
  std::cout << "\tPop: ";
  while (!cque.IsEmpty()) {
    std::cout << cque.Pop() << ' ';
  }
  std::endl(std::cout);
  std::cout << "\t<--- cirqular que" << std::endl;
  return 1;
}
}  // namespace circular_que

#endif // CIRCULAR_QUE_H__
