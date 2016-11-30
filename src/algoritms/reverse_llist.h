#ifndef _REVERSE_LLIST_H
#define _REVERSE_LLIST_H
#include "common_data.h"

namespace reverse_llist_test {
class SList {
    SList(): data(0), next(0) {}
    SList(int d): data(d), next(0) {}
    int data;
    SList *next;
};

SList * iter_rev_llist(SList *);
SList * rec_rev_llist(SList *);
SList * recursive_reverse_linked_list_2(SList * node, SList * prev);

void fill_slist(SList * head, int size) {
  SList *temp = head;
  for (int i = 1; i < size ; ++i) {
    SList *node= new SList();
    node->data = i;
    node->next = NULL;
    temp->next = node;
    temp = node;
  }
}

void print_slist(SList * head) {
  SList * temp = head;
  while (temp) {
    printf(" %d", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

//Reverse a linked list.
int test() {
  printf("reverse_llist_test::test\n");
  SList * list = new SList(0);
  fill_slist(list, 20);
  print_slist(list);
  printf("iterative reverse linked list\n");

  list = iter_rev_llist(list);
  print_slist(list);
  printf("recursive reverse linked list\n");
  list = rec_rev_llist(list);
  print_slist(list);
  printf("recursive reverse linked list 2\n");
  list = recursive_reverse_linked_list_2(list, 0);
  print_slist(list);

  printf("\n");
  return 0;
}

SList* iter_rev_llist(SList * n) {
  if (!n || !n->next)
    return n;
  SList *rev = 0, *tmp = 0;
  while (n) {
    tmp = n;
    n = n->next;
    tmp->next = rev;
    rev = tmp;

  }
  n = rev;
  return n;

}

SList * rec_rev_llist(SList * n) {
  if (!n || !n->next)
    return n;
  SList * rec = rec_rev_llist(n->next);
  n->next->next = n;
  n->next = 0;
  return rec;
}

SList * recursive_reverse_linked_list_2(SList * node, SList * prev) {
  if (!node->next) {
    node->next = prev;
    return node;
  }
  SList * tmp;
  tmp = recursive_reverse_linked_list_2(node->next, node);
  node->next = prev;
  return tmp;
}

}
#endif //_REVERSE_LLIST_H
