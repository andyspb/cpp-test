#ifndef _ALGO_25_H
#define _ALGO_25_H
#include "common_data.h"
SList * iterative_reverse_linked_list(SList * head);
SList * recursive_reverse_linked_list(SList * node);
SList * recursive_reverse_linked_list_2(SList * node, SList * prev);

//Reverse a linked list. 
int algo_25() {
  printf("algo_25: test\n");
  SList * list = new SList(0);
  fill_slist(list, 20);
  print_slist(list);
  printf("iterative reverse linked list\n");
  //SList * temp = 0;
  //SList * reverse = 0;
  //while ( list )
  //{
  //    temp = list;
  //    list = list->next;
  //    temp->next = reverse;
  //    reverse = temp;
  //}
  //list = reverse;
  list = iterative_reverse_linked_list(list);
  print_slist(list);
  /*printf("recursive reverse linked list\n");
   list = recursive_reverse_linked_list(list);
   print_slist(list);
   printf("recursive reverse linked list 2\n");
   list = recursive_reverse_linked_list_2(list,0);
   print_slist(list);
   */
  printf("\n");
  return 0;
}

SList* iterative_reverse_linked_list(SList * head) {
  SList * temp = 0;
  SList * reverse = 0;
  while (head) {
    temp = head;
    head = (head)->next;
    temp->next = reverse;
    reverse = temp;
  }
  head = reverse;
  return head;
}

SList * recursive_reverse_linked_list(SList * node) {
  SList * tmp;
  if (!(node && node->next))
    return node;

  tmp = recursive_reverse_linked_list(node->next);
  node->next->next = node;
  node->next = 0;
  return tmp;
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

#endif //_ALGO_25_H
