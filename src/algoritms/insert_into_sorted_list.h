#ifndef _INSERT_INTO_SORTED_LIST_H_
#define _INSERT_INTO_SORTED_LIST_H_

#include <iostream>
namespace insert_into_sorted_slist {
struct SList {
  SList(int i)
      : val_(i),
        next_(0) {
  }
  int val_;
  struct SList * next_;
};
void fill_slist(SList * head) {
  if (!head) {
    return;
  }
  SList *temp = head;
  int arr[14] = { 1, 2, 90, 92, 111, 222, 333, 444, 555, 666, 777, 888, 999,
      1000 };
  for (int i = 0; i < 14; ++i) {
    temp->next_ = new SList(arr[i]);
    temp = temp->next_;
  }
}

void print_slist(SList * head) {
  if (!head) {
    return;
  }
  SList * temp = head;
  while (temp) {
    std::cout << temp->val_ << " ";
    temp = temp->next_;
  }
  std::endl(std::cout);
  return;
}

void insert(SList** list, int n) {
  if (!list)
    return;
  if (!(*list)) {
    SList * node = new SList(n);
    (*list) = node;
    return;
  }
  SList * t = *list;
  SList * s = t;
  while (t && t->val_ < n) {
    s = t;
    t = t->next_;
  }
  s->next_ = new SList(n);
  if (t) {
    s->next_->next_ = t;
  }
}

TEST_RESULT test() {
  __SCOPE_LOG__;
  SList *list = new SList(-1);
  fill_slist(list);
  print_slist(list);
  insert(&list, 111);
  print_slist(list);
  std::cout << "<--- test insertsort passed" << std::endl;
  RETURN_OK();
}
}  // namespace insert_into_sorted_slist

#endif //_INSERT_INTO_SORTED_LIST_H_
