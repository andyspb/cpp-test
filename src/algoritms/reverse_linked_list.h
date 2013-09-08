#ifndef _REVERSE_LINKED_LIST_H_
#define _REVERSE_LINKED_LIST_H_

#include <iostream>

namespace reverse_linkedlist {

// single linked list
template<typename T>
struct List {
    T val;
    struct List *next;
};

template<typename T>
List<T> * reverse_iterate(List<T> * head) {
  if (!head || !head->next)
    return head;
  List<T> *t(0), *r(0);
  while (head) {
    t = head;
    head = head->next;
    t->next = r;
    r = t;
  }
  return r;
}

template<typename T>
List<T> * reverse_recursive(List<T> *head) {
  if (!head || !head->next)
    return head;
  List<T> *r(reverse_recursive(head->next));
  head->next->next = head;
  head->next = 0;
  return r;
}

template<typename T>
void print_slist_int(List<T> * head) {
  List<T> * temp = head;
  while (temp) {
    std::cout << " " << static_cast<int>(temp->val);
    temp = temp->next;
  }
  std::endl(std::cout);
}

template<typename T>
void fill_slist(List<T> * head, int size) {
}

int test() {
  std::cout << "Test: reverse liked list --->" << std::endl;

  List<int> *list = new List<int>();
  list->val = 0;
  list->next = NULL;

  List<int> *temp = list;
  for (int i = 1; i < 20 ; ++i) {
    List<int> *l = new List<int>();
    l->val = i;
    l->next = NULL;
    temp->next = l;
    temp = l;
  }

  print_slist_int(list);
  list = reverse_iterate(list);
  print_slist_int(list);

  list = reverse_recursive(list);
  print_slist_int(list);

  std::cout << "<--- test passed" << std::endl;
  return 1;
}


}  // namespace reverse_linkedlist

#endif  // _REVERSE_LINKED_LIST_H_

