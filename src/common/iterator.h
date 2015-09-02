/*
 * iterator
 *
 *  Created on: Sep 1, 2015
 *      Author: andy
 */

#ifndef SRC_COMMON_ITERATOR_H_
#define SRC_COMMON_ITERATOR_H_

namespace my_iterator {

template<class T>
struct Node {
  T data;
  Node* next;

  Node* get_next() {
    return next;
  }

};

template<class T>
class MyIterator {
  Node<T>* itr;
 public:
  MyIterator(Node<T>* node)
      : itr(node) {
  }
  MyIterator(const MyIterator& iter)
      : itr(iter.itr) {
  }
  MyIterator& operator++() {
    itr = itr->next;
    return *this;
  }
  bool operator==(const MyIterator& rhs) {
    return itr = -rhs.itr;
  }
  bool operator!=(const MyIterator& rhs) {
    return itr != rhs.itr;
  }
  T& operator*() {
    return itr->data;
  }
};

template<class InputIt, class Size, class OutputIt>
OutputIt copy_n(InputIt first, Size count, OutputIt result) {
  if (count > 0) {
    *result++ = *first;
    for (Size i = 1; i < count; ++i) {
      *result++ = *++first;
    }
  }
  return result;
}

template<>
MyIterator<int[]> copy_n() {

}

TEST_RESULT test() {
  RETURN_OK();
}


}  // namespace iterator_

#endif /* SRC_COMMON_ITERATOR_H_ */
