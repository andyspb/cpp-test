/*
 * circular_que.h
 *
 *  Created on: 15 дек. 2013 г.
 *      Author: andy
 */

#ifndef CIRC_QUE_H_
#define CIRC_QUE_H_

#include <iostream>

namespace circ_que {

template<typename T>
class CircQue {
 private:
  enum {
    default_max = 10
  };

  size_t head;
  size_t tail;
  size_t size;
  size_t capacity;
  T * data;
 public:
  CircQue(size_t max_size = default_max)
      : head(0),
        tail(0),
        size(0),
        capacity(max_size),
        data(new T[capacity]) {
  }

  ~CircQue() {
    delete[] data;
  }

  size_t Size() const {
    return size;
  }
  size_t Capacity() const {
    return capacity;
  }
  bool IsEmpty() const {
    return size == 0;
  }
  bool IsFull() {
    return size == capacity;
  }

  T Top() const {
    if (IsEmpty()) {
      throw "empty";
    }
    return data[head];
  }

  void Push(const T& val) {
    if (IsFull()) {
      std::cout << " CQue is full ...";
      return;
    }
    data[tail] = val;
    tail = (tail + 1) % capacity;
    ++size;
  }
  T Pop() {
    if (IsEmpty()) {
      throw "empty";
    };
    T tmp = data[head];
    head = (head + 1) % capacity;
    --size;
    return tmp;
  }
};

int test() {
  std::cout << "\tcircular que --->" << std::endl;
  CircQue<int> cque(6);
  std::cout << "\tCQue capacity: " << cque.Capacity() << std::endl;
  std::cout << "\tPush: ";
  for (int i = 1; i < 15; ++i) {
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
  std::cout << "\t<--- circular que" << std::endl;
  return 1;
}

}  // namespace circ_que

#endif /* CIRC_QUE_H_ */
