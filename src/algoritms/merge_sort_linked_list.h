#ifndef _MERGE_SORT_LINKED_LIST_H_
#define _MERGE_SORT_LINKED_LIST_H_

#include <iostream>

namespace mergesort_linkedlist {
// single linked list
template<typename T>
struct SList {
    T val;
    struct SList *next;
};

/* merge the lists.. */
template<typename T>
SList<T> *merge(SList<T> *h1, SList<T> *h2) {
  // temporal
  SList<T> *h3;

  if (!h1)
    return h2;

  if (!h2)
    return h1;

  if (h1->val < h2->val) {
    h3 = h1;
    h3->next = merge(h1->next, h2);
  } else {
    h3 = h2;
    h3->next = merge(h1, h2->next);
  }

  return h3;
}

template<typename T>
SList<T> *mergesort(SList<T> *head) {
  SList<T> *h1 = NULL, *h2 = NULL;

  if (!head || !head->next)
    return head;

  h1 = head;
  h2 = head->next;
  while (h2 && h2->next) {
    head = head->next;
    h2 = head->next->next;
  }
  h2 = head->next;
  head->next = 0;

  return merge(mergesort(h1), mergesort(h2));
}

int test() {
  std::cout << "Test: mergesort for linked list --->" << std::endl;

  struct SList<int> * list = new SList<int>();
  list->val = 0;
  list->next = NULL;

  SList<int> * sl = list;
  for (int i = 1; i < 35; i++) {
    sl->next = new SList<int>();
    sl->next->next = NULL;
    sl->next->val = 36 - i;  //( i * 345) % 100;
    sl = sl->next;
  }
  sl = list;
  while (sl) {
    std::cout << " " << sl->val;
    sl = sl->next;
  }
  std::endl(std::cout);

  list = mergesort(list);
  sl = list;
  while (sl) {
    std::cout << " " << sl->val;
    sl = sl->next;
  }
  std::endl(std::cout);
  return 1;
}
}  // namespace mergesort_linkedlist

#endif //  _MERGE_SORT_LINKED_LIST_H_
