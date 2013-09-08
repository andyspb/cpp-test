#ifndef _ALGO_21_H
#define _ALGO_21_H

#include "common_data.h"
//Delete an element from a doubly linked list.
int remove_Nth_from_dlist(DList ** list, int n);

void algo_21() {
  printf("algo_21 test: Delete an element from a doubly linked list.\n");
  DList * dlist_head = new DList(0);
  fill_dlist(dlist_head, 25);
  print_dlist(dlist_head);
  remove_Nth_from_dlist(&dlist_head, 25);
  print_dlist(dlist_head);

  return;
}

int remove_Nth_from_dlist(DList ** list, int n) {
  if (n < 0) {
    return -1;
  }
  DList * p = *list;
  while (p && n > 0) {
    p = p->next;
    n--;
  }
  if (p) {
    if (p->prev) {
      p->prev->next = p->next;
    } else {
      *list = (*list)->next;
    }
    if (p->next) {
      p->next->prev = p->prev;
    }
    delete (p);
    return 0;
  }
  return -1;

}

#endif //_ALGO_22_H
