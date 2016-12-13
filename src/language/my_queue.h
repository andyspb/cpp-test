#ifndef _MY_QUEUE_H_
#define _MY_QUEUE_H_

#include <iostream>

namespace my_queue {
template<typename T>
struct Node {
    T value;
    Node *prev;
};

template<typename T>
class My_Queue {
  public:
    My_Queue()
        : m_size(0), m_pTopElem(0), m_pLastElem(0) {
    }
    ;
    ~My_Queue() {
    }
    ;
    //access next elem
    void front(T* pVal) {
      //T value;
      if (m_pTopElem) {
        *pVal = m_pTopElem->value;
      }
    }

    //access last elem
    void back(T* pVal) {
      if (m_pLastElem) {
//				*pVal = m_pLastElem.value;
      }
    }

    //adds new elem at the end of queue, increasing size
    void push(const T& data) {
      Node<T> *newNode = new Node<T>();
      newNode->value = data;
      if (m_pLastElem) {
        m_pLastElem->prev = newNode;
      }
      m_pLastElem = newNode;
      ++m_size;
      if (m_size == 1) {
        m_pTopElem = m_pLastElem;
      }
    }

    //removes next elem in que, reducing size;
    void pop() {
      if (m_pTopElem) {
        Node<T>* tmp;
        tmp = m_pTopElem;
        m_pTopElem = m_pTopElem->prev;
        delete tmp;
        --m_size;
      }
    }

    //return size of the container
    size_t size() {
      return m_size;
    }
    bool IsEmpty() {
      return m_size == 0;
    }
  private:
    size_t m_size;
    Node<T>* m_pTopElem;
    Node<T>* m_pLastElem;

};

int test() {
  int n = 20;
  std::cout << "my queue test:n=" << n << "\n";
  My_Queue<int> que;
  for (int i = 0; i < n; ++i) {
    que.push(i);
    std::cout << i << ' ';
  }

  std::endl(std::cout);
  std::cout << "que size:" << que.size() << std::endl;

  for (int i = 0; i < n; ++i) {
    int n;
    que.front(&n);
    std::cout << n << ' ';
    que.pop();
  }

  std::endl(std::cout);
  std::cout << "que size:" << que.size() << std::endl;
  return 1;
}
}  // my_queue

#endif  // _MY_QUEUE_H_
