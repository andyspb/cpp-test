#ifndef _CONTAINER_STACK_TEST_H_
#define _CONTAINER_STACK_TEST_H_

//Write stack container interface
//Add facilities to assign minimum number of elements
//Add method to fetch a head element
//Implement methods

namespace container_stack_test {

#include <list>
#include <iostream>

struct DefStackTraits {
  static const int MIN_ELEMENT_COUNT_ = 10;
  typedef int int_t;
};

template<typename T, typename Traits = DefStackTraits>
class Stack {
 private:
  typedef std::list<T> List_t;
  List_t items_;
  size_t capacity_;
  size_t size_;

 public:
  Stack(int capacity = DefStackTraits::MIN_ELEMENT_COUNT_)
      : capacity_(capacity) {
    items_.resize(capacity_);
  }
  ~Stack() {
  }

  T pop() {
    T elem = items_.front();
    items_.pop_front();
    return elem;
  }

  void push(const T& el) {
    items_.push_front(el);
  }

  bool empty() const {
    return items_.empty();
  }

  int size() const {
    return static_cast<int>(items_.size());
  }

  const T& front() const {
    return items_.front();
  }
};

// test routine
int test() {
  std::cout << "Test: test for stack container:" << std::endl;
  Stack<int> stack;
  std::cout << "\tadd items: ";
  for (int i = 0; i < 10; ++i) {
    std::cout << i << " ";
    stack.push(i);
  }
  std::endl(std::cout);
  std::cout << "\tget items: ";
  for (int i = 0; i < stack.size(); ++i) {
    std::cout << stack.pop() << " ";
  }
  std::endl(std::cout);
  std::cout << "<--- container stack test passed" << std::endl;
  return 1;
}
}  // namespace container_stack_test
#endif // _CONTAINER_STACK_TEST_H_
