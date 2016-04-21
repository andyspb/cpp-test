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
  if (!head || !head->next) {
    return head;
  }
  List<T> *temp(0), *rev(0);
  while (head) {
    temp = head;
    head = head->next;
    temp->next = rev;
    rev = temp;
  }
  return rev;
}

template<typename T>
List<T> * reverse_recursive(List<T> *head) {
  if (!head || !head->next)
    return head;
  List<T> *rec = reverse_recursive(head->next);
  head->next->next = head;
  head->next = 0;
  return rec;
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

template<int>
void fill_slist(List<int> * head, int size) {
  List<int> *temp = head;
  for (int i = 1; i < size ; ++i) {
    List<int> *node= new List<int>();
    node->val = i;
    node->next = NULL;
    temp->next = node;
    temp = node;
  }
}

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__ <<  " Test: reverse liked list --->";

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

  LOG(INFO) << __PRETTY_FUNCTION__ << " Print origin list" ;

  print_slist_int(list);

  LOG(INFO) << __PRETTY_FUNCTION__ << " Reverse iterative";
  list = reverse_iterate(list);
  print_slist_int(list);

  LOG(INFO) << __PRETTY_FUNCTION__ << " Reverse recursive";
  list = reverse_recursive(list);
  print_slist_int(list);
  RETURN_OK();
}


}  // namespace reverse_linkedlist

#endif  // _REVERSE_LINKED_LIST_H_

