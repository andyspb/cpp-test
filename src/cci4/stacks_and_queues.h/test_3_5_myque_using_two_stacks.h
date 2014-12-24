#ifndef TEST_3_5_MYQUE_USING_TWO_STACKS_H_
#define TEST_3_5_MYQUE_USING_TWO_STACKS_H_

#include <stack>
#include <iostream>

namespace test_3_5 {
template<class T>
class MyQueue {
    std::stack<T> s1, s2;
  public:
    MyQueue() {
    }
    int size() {
      return static_cast<int>(s1.size() + s2.size());
    }
    void add(T value) {
      s1.push(value);
    }
    T peek() {
      if (!s2.empty())
        return s2.top();
      while (!s1.empty()) {
        int v = s1.top();
        s2.push(v);
        s1.pop();
      }
      return s2.peek();
    }
    T remove() {
      if (!s2.empty()) {
        int v = s2.top();
        s2.pop();
        return v;
      }
      while (!s1.empty()) {
        int v = s1.top();
        s2.push(v);
        s1.pop();
      }
      int v = s2.top();
      s2.pop();
      return v;
    }
};
int test() {
  std::cout << "Test 3.5" << std::endl;
  MyQueue<int> myque;
  myque.add(1);
  myque.add(2);
  myque.add(3);
  myque.add(4);
  myque.add(5);
  myque.add(6);

  while (myque.size() > 0) {
    std::cout << myque.remove() << " ";
  }
  std::endl(std::cout);
  return 1;
}
} // namespace test_3_6

#endif /* TEST_3_5_MYQUE_USING_TWO_STACKS_H_ */
