/*
 * generic_linked_list_in_c.h
 *
 *  Created on: 20 апр. 2015 г.
 *      Author: andy
 */

#ifndef GENERIC_LINKED_LIST_IN_C_H_
#define GENERIC_LINKED_LIST_IN_C_H_

struct GenericLinkedList {
  void *data;
  struct GenericLinkedList* next;
};

/* Function to add a node at the beginning of Linked List.
 This function expects a pointer to the data to be added
 and size of the data type */
void push(GenericLinkedList** head_ref, void* new_data, int data_size) {
  // Allocate memory for head_ref
  struct GenericLinkedList* new_node = (GenericLinkedList*) malloc(
      sizeof(struct GenericLinkedList));
  new_node->data = malloc(data_size);
  new_node->next = head_ref;

  // copy data to newly created new_node
  int i;
  for (int i = 0; i < data_size; ++i) {
    *(char*) (new_node->data + i) = *(char*) (new_data + i);
  }
  *head_ref = new_node;
}

void push_back(GenericLinkedList* head_ref, void* new_data, int data_size) {
  // Allocate memory for head_ref
  struct GenericLinkedList* new_node = (GenericLinkedList*) malloc(
      sizeof(struct GenericLinkedList));
  new_node->data = malloc(data_size);
  new_node->next = 0;
  head_ref->next = new_node;

  // copy data to newly created new_node
  int i;
  for (int i = 0; i < data_size; ++i) {
    *(char*) (new_node->data + i) = *(char*) (new_data + i);
  }
  head_ref->next = new_node;
}

#endif /* GENERIC_LINKED_LIST_IN_C_H_ */
