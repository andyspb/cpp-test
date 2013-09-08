#pragma once
//Write C code for (a) deleting an element from a linked list (b) traversing a linked list
#include "common_data.h"

void remove_from_slist(SList **, int);

void algo_62() {
  int delete_elem = 10;
  printf("Algo 62, deleting %d element from linked list;\n", delete_elem);

  SList * node = new SList(0);
  fill_slist(node, 25);

  print_slist(node);

  remove_from_slist(&node, delete_elem);

  print_slist(node);
}

void remove_from_slist(SList ** node, int n) {
  if (!(*node) || n < 0)
    return;
  if (n == 0) {
    SList * temp = *node;
    *node = (*node)->next;
    delete (temp);
    return;
  }

  SList * p = (*node);
  SList * s = 0;
  while (p && n > 0) {
    s = p;
    p = p->next;
    n--;
  }
  if (p) {
    s->next = p->next;
    delete (p);
  }
}
