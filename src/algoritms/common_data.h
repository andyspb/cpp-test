#ifndef _COMMON_DATA_H
#define _COMMON_DATA_H
#include <stdio.h>
#include <string.h>
//#include "test_ansi.h"

struct SList {
  SList(int i)
      : data(i),
        next(0) {
  }
  int data;
  SList * next;
};

struct DList {
  DList(int i)
      : data(i),
        next(0),
        prev(0) {
  }
  int data;
  DList * next;
  DList * prev;
};

struct BTreeNode {
  BTreeNode(int i)
      : data(i),
        left(0),
        right(0) {
  }
  int data;
  BTreeNode * left;
  BTreeNode * right;
};

void fill_slist(SList * head, int num) {
  if (head == 0 || num <= 0) {
    return;
  }
  SList * temp = head;
  for (int i = 0; i < num; i++) {
    temp->next = new SList(i + 1);
    temp = temp->next;
  }
}

void fill_dlist(DList * head, int num) {
  if (!head || num <= 0) {
    return;
  }
  DList * temp = head;
  for (int i = 0; i < num; i++) {
    DList * prev = temp;
    temp->next = new DList(i + 1);
    temp = temp->next;
    temp->prev = prev;
  }
}

void print_dlist(DList * head) {
  if (!head) {
    return;
  }
  DList * node = head;
  while (node) {
    printf(" %d", node->data);
    node = node->next;
  }
  printf("\n");
  return;
}
int btree_data = 0;

void fill_tree(BTreeNode *root, int& number) {
  if (!root || number == 0)
    return;

  BTreeNode * tmp = root;
  while (number != 0) {
    BTreeNode * leftNode = new BTreeNode(++btree_data);
    BTreeNode * rightNode = new BTreeNode(++btree_data);
    tmp->left = leftNode;
    tmp->right = rightNode;
    number -= 1;
    fill_tree(leftNode, number);
    fill_tree(rightNode, number);
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

typedef struct slist_ {
  long val;
  struct slist_ *next;
} slist;

#endif //_COMMON_DATA_H
