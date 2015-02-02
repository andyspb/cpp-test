/*
 * intersection_point_of_two_linked_lists.h
 *
 *  Created on: Feb 2, 2015
 *      Author: andy
 */

#ifndef INTERSECTION_POINT_OF_TWO_LINKED_LISTS_H_
#define INTERSECTION_POINT_OF_TWO_LINKED_LISTS_H_

#include<stdio.h>
#include<stdlib.h>

namespace intersection_point_of_two_linked_lists {
/* Link list node */
struct node {
  int data;
  struct node* next;
};

/* Function to get the counts of node in a linked list */
int getCount(struct node* head);

/* function to get the intersection point of two linked
 lists head1 and head2 where head1 has d more nodes than
 head2 */
int _getIntesectionNode(int d, struct node* head1, struct node* head2);

/* function to get the intersection point of two linked
 lists head1 and head2 */
int getIntesectionNode(struct node* head1, struct node* head2) {
  int c1 = getCount(head1);
  int c2 = getCount(head2);
  int d;

  if (c1 > c2) {
    d = c1 - c2;
    return _getIntesectionNode(d, head1, head2);
  } else {
    d = c2 - c1;
    return _getIntesectionNode(d, head2, head1);
  }
}

/* function to get the intersection point of two linked
 lists head1 and head2 where head1 has d more nodes than
 head2 */
int _getIntesectionNode(int d, struct node* head1, struct node* head2) {
  int i;
  struct node* current1 = head1;
  struct node* current2 = head2;

  for (i = 0; i < d; i++) {
    if (current1 == NULL) {
      return -1;
    }
    current1 = current1->next;
  }

  while (current1 != NULL && current2 != NULL) {
    if (current1 == current2)
      return current1->data;
    current1 = current1->next;
    current2 = current2->next;
  }

  return -1;
}

/* Takes head pointer of the linked list and
 returns the count of nodes in the list */
int getCount(struct node* head) {
  struct node* current = head;
  int count = 0;

  while (current != NULL) {
    count++;
    current = current->next;
  }

  return count;
}

/* IGNORE THE BELOW LINES OF CODE. THESE LINES
 ARE JUST TO QUICKLY TEST THE ABOVE FUNCTION */
int test() {
  /*
   Create two linked lists

   1st 3->6->9->15->30
   2nd 10->15->30

   15 is the intersection point
   */

  struct node* newNode;
  struct node* head1 = (struct node*) malloc(sizeof(struct node));
  head1->data = 10;

  struct node* head2 = (struct node*) malloc(sizeof(struct node));
  head2->data = 3;

  newNode = (struct node*) malloc(sizeof(struct node));
  newNode->data = 6;
  head2->next = newNode;

  newNode = (struct node*) malloc(sizeof(struct node));
  newNode->data = 9;
  head2->next->next = newNode;

  newNode = (struct node*) malloc(sizeof(struct node));
  newNode->data = 15;
  head1->next = newNode;
  head2->next->next->next = newNode;

  newNode = (struct node*) malloc(sizeof(struct node));
  newNode->data = 30;
  head1->next->next = newNode;

  head1->next->next->next = NULL;

  printf("\n The node of intersection is %d \n",
         getIntesectionNode(head1, head2));
  return 1;

}

}  // namespace intersection_point_of_two_linked_lists

#endif /* INTERSECTION_POINT_OF_TWO_LINKED_LISTS_H_ */
