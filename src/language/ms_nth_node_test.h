#include "ms_common.h"

void fill_linked_list(ms_common::List * head, int numbers);
void print_linked_list(ms_common::List * head);
ms_common::List * find_nth_element_from_end(ms_common::List * head,
                                            int element);
void copy_linked_list(ms_common::List *q, ms_common::List **s);
void print_linked_list_from_end(ms_common::List * head);

void myfunction(int *ptr) {
  int myvar = 100;
  ptr = &myvar;
}

void nth_node_test(int element, int size) {
  printf("nth_node_test\n");
  int *myptr = 0;
  myfunction(myptr);
  if (size <= 0) {
    printf("incorrect list size %d\n", size);
    return;
  }
  if (size < element) {
    printf("element %d more than size %d\n", element, size);
  }

  ms_common::List * node = new ms_common::List(0);
  ms_common::List * head = node;
  fill_linked_list(node, size);
  print_linked_list(head);

  int data = find_nth_element_from_end(head, element)->data;
  printf("Element %d from list end is %d\n", element, data);
  ms_common::List * tmp = NULL;
  ms_common::List * reverse_list = NULL;

  while (head) {

    tmp = head;
    head = head->next;

    tmp->next = reverse_list;
    reverse_list = tmp;
  }
  head = reverse_list;
  printf("Print reverse list:\n");
  print_linked_list(head);

  ms_common::List * new_node = NULL;
  copy_linked_list(head, &new_node);
  tmp = NULL;
  reverse_list = NULL;

  while (new_node) {

    tmp = new_node;
    new_node = new_node->next;

    tmp->next = reverse_list;
    reverse_list = tmp;
  }
  new_node = reverse_list;

  ms_common::List * n = head;
  print_linked_list(new_node);

  print_linked_list_from_end(new_node);
  printf("\n");

}

void fill_linked_list(ms_common::List * node, int numbers) {
  if (numbers <= 0) {
    return;
  }
  for (int i = 1; i <= numbers; i++) {
    ms_common::List * temp_node = new ms_common::List(i);
    node->next = temp_node;
    node = temp_node;
  }

}

void print_linked_list(ms_common::List *head) {
  ms_common::List * node = head;
  while (node) {
    printf(" %2d", node->data);
    node = node->next;
  }
  printf("\n");
}

ms_common::List * find_nth_element_from_end(ms_common::List * head,
                                            int element) {
  ms_common::List * tmp = head;
  ms_common::List * behind_tmp = 0;
  tmp = head;
  for (int i = 0; i < element; i++) {
    if (tmp->next) {
      tmp = tmp->next;
    } else {
      return 0;
    }
  }
  behind_tmp = head;
  while (tmp->next) {
    tmp = tmp->next;
    behind_tmp = behind_tmp->next;
  }
  return behind_tmp;

}

void copy_linked_list(struct ms_common::List *q, ms_common::List **s) {
  if (q) {
    *s = (ms_common::List *) malloc(sizeof(ms_common::List));
    (*s)->data = q->data;
    (*s)->next = 0;
    copy_linked_list(q->next, &((*s)->next));
  }
}

void print_linked_list_from_end(ms_common::List * head) {
  if (!head) {
    return;
  }
  print_linked_list_from_end(head->next);

  printf(" %2d", head->data);

}
