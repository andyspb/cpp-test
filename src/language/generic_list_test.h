#ifndef GENERIC_LIST_TEST_H__
#define GENERIC_LIST_TEST_H__

#include <iostream>
#include <assert.h>
// Define generic linked list
// Add element to the list, front, middle and tail
// Reverse the list
// Test it
namespace generic_list_test {
template<class T>
class Node {
  public:
    Node(T& value)
        : value_(value), next_(NULL) {
    }
    T value_;
    Node<T> * next_;
};

template<class T>
class List {
  public:
    List()
        : first_(NULL), last_(NULL), size_(0) {
    }
    ~List() {
      clean();
    }

    bool empty() const {
      return first_ == NULL;
    }

    int size() const {
      return size_;
    }

    T& back() {
      return last_->value_;
    }
    T& front() {
      return first_->value_;
    }
    void push_front(T value) {
      Node<T>* node = new Node<T>(value);
      if (empty())
        first_ = last_ = node;
      else {
        node->next_ = first_;
        first_ = node;
      }
      ++size_;
    }
    void push_back(T value) {
      Node<T>* node = new Node<T>(value);
      if (empty()) {
        first_ = last_ = node;
      } else {
        last_->next_ = node;
        last_ = node;
      }
      ++size_;
    }
    void push_middle(T value, int pos) {
      if (pos < 0) {
        return;
      }
      if (pos == 0) {
        push_front(value);
        return;
      }
      if (pos >= size_) {
        push_back(value);
        return;
      }
      Node<T>* node = new Node<T>(value);
      if (empty()) {
        first_ = last_ = node;
      } else {
        Node<T>* n1 = first_;
        while (--pos > 0) {
          n1 = n1->next_;
        }
        Node<T>* n2 = n1->next_;
        n1->next_ = node;
        node->next_ = n2;
      }
      ++size_;
    }

    void reverse() {
      if (!first_ || !first_->next_)
        return;
      Node<T> *n1, *n2 = 0;
      last_ = first_;
      while (first_) {
        n1 = first_;
        first_ = first_->next_;
        n1->next_ = n2;
        n2 = n1;
      }
      first_ = n1;
      last_->next_ = NULL;
    }

    void clean() {
      Node<T> * first = first_;
      while (first != NULL) {
        Node<T>* next = first->next_;
        delete first;
        first = next;
      }
      first_ = NULL;
      last_ = NULL;
      size_ = 0;
    }
    // giving access to print data
    // protected:
    Node<T>* first_;
    Node<T>* last_;
    int size_;
};

int test_push_front(List<int>& list) {
  int nodes = 10;
  std::cout << "\tpush_front() with " << nodes << "\n";
  list.clean();
  for (int i = 0; i < nodes; ++i) {
    list.push_front(i);
  }
  return (list.back() == 0 && list.front() == (nodes - 1)
      && list.size() == nodes);
}

int test_push_back(List<int>& list) {
  int nodes = 10;
  std::cout << "\tpush_back() with " << nodes << "\n";
  list.clean();
  for (int i = 0; i < nodes; ++i) {
    list.push_back(i);
  }
  return (list.front() == 0 && list.back() == (nodes - 1)
      && list.size() == nodes);
}

bool test_push_middle(List<int>& list) {
  int nodes = 10;
  std::cout << "\ttest_push_middle() with " << nodes << " and " << nodes + 1
      << " in middle\n";
  list.clean();
  for (int i = 0; i < 10; ++i) {
    list.push_back(i);
  }
  int middle_value = nodes + 1;
  int middle_pos = list.size() >> 1; // make middle
  list.push_middle(middle_value, middle_pos);
  Node<int>* node = list.first_;
  while (--middle_pos >= 0) {
    node = node->next_;
  }
  return (list.size() == (nodes + 1) && node && node->value_ == middle_value);
}

bool test_reverse(List<int>& list) {
  int nodes = 10;
  std::cout << "\ttest_reverse() with " << nodes << " values\n";
  list.clean();
  for (int i = 0; i < nodes; ++i) {
    list.push_back(i);
  }
  List<int> l;
  for (int i = nodes - 1; i >= 0; --i) {
    l.push_back(i);
  }
  list.reverse();
  Node<int>* n1 = list.first_;
  Node<int>* n2 = l.first_;
  while (n1 && n2) {
    if (n1->value_ != n2->value_) {
      return 0;
    }
    n1 = n1->next_;
    n2 = n2->next_;
  }
  return (list.size() == l.size());
}

int test() {
  std::cout << "Test: generic_list_test ---> \n";
  List<int> list;
  assert(test_push_front(list));
  assert(test_push_back(list));
  assert(test_push_middle(list));
  assert(test_reverse(list));
  std::cout << "<--- generic_list_test passed\n";
  return 1;
}
}  // namespace generic_list_test

#endif //  GENERIC_LIST_TEST_H__
