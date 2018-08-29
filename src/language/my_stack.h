#ifndef _MY_STACK_H_
#define _MY_STACK_H_

#include<iostream>
namespace my_stack {
template<typename T>
struct Node {
  T data;
  Node* prev;
};

template<typename T>
class My_Stacks {
 public:
  My_Stacks()
      : m_size(0),
        m_pTopNode(NULL) {
  }
  virtual ~My_Stacks() {
  }
  void push(T data) {
    Node<T>* tmp = new Node<T>();
    tmp->prev = m_pTopNode;
    tmp->data = data;
    m_pTopNode = tmp;
    ++m_size;
  }

  void pop(T *p) {
    *p = m_pTopNode->data;
    Node<T>* tmp;
    tmp = m_pTopNode;
    m_pTopNode = m_pTopNode->prev;
    delete tmp;
    --m_size;
  }

  T* top() {
    return m_pTopNode;
  }

  void clear() {
    if (m_pTopNode == NULL)
      return;
    Node<T>* tmp = m_pTopNode;
    while (true) {
      if (m_pTopNode->prev != NULL) {
        tmp = m_pTopNode;
        m_pTopNode = m_pTopNode->prev;
        delete tmp;
      } else {
        delete m_pTopNode;
        break;
      }
    }
  }
  size_t size() {
    return m_size;
  }
  bool empty() {
    return (m_pTopNode == NULL);
  }
 private:
  size_t m_size;
  Node<T>* m_pTopNode;
};

int test() {
  My_Stacks<int> stack;
  for (int i = 0; i < 10; ++i) {
    std::cout << i << ' ';
    stack.push(i);
  }
  std::endl(std::cout);
  std::cout << "stack size=" << stack.size() << std::endl;

  for (int i = 0; i < 10; ++i) {
    int tmp = -1;
    stack.pop(&tmp);
    std::cout << tmp << ' ';
  }
  std::endl(std::cout);

  std::cout << "stack size=" << stack.size();
  return 1;
}
}  // namespace my_stack

#endif  // _MY_STACK_H_
