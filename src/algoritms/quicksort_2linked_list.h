/*
 * quicksort_2linked_list.h
 *
 *  Created on: 03 янв. 2015 г.
 *      Author: andy
 */

#ifndef QUICKSORT_2LINKED_LIST_H_
#define QUICKSORT_2LINKED_LIST_H_

#include <stdio.h>

namespace qsort_2linked_list {

// double linked list node
typedef struct Node {
  int value;
  struct Node *prev;
  struct Node *next;
} IntList;

// ptr to first and last nodes
IntList *g_First = NULL;
IntList *g_Last = NULL;

// adding to list
void AddListItem(int value) {
  IntList *pItem = new IntList;
  pItem->value = value;
  if (g_First == NULL) {
    g_First = g_Last = pItem;
    pItem->next = pItem->prev = NULL;
  } else {
    g_Last->next = pItem;
    pItem->prev = g_Last;
    g_Last = pItem;
    pItem->next = NULL;
  }
}

// removing
void RemoveAllItems() {
  IntList *del, *node = g_First;

  while (node != NULL) {
    del = node;
    node = node->next;
    delete del;
  }
  g_First = g_Last = NULL;
}

// print list content
void PrintList() {
  IntList *pItem = g_First;

  while (pItem != NULL) {
    printf("%d ", pItem->value);
    if (pItem->next)
      printf("-> ");
    pItem = pItem->next;
  }
  printf("\n");
}

// quick sort
void QuickSortList(IntList *left, IntList *right) {
  IntList *start;
  IntList *curr;
  int nCopyInteger;

  // sorting ended - return
  if (left == right)
    return;

  // установка двух рабочих указателей - Start и Current
  start = left;
  curr = start->next;

  // итерация по списку слева направо
  while (1) {
    // элемент с максимальным значением помещается в начало списка
    if (start->value < curr->value) {
      nCopyInteger = curr->value;
      curr->value = start->value;
      start->value = nCopyInteger;
    }

    if (curr == right)
      break;
    curr = curr->next;
  }

  // переключение First и Current - максимум попадает в правый конец списка
  nCopyInteger = left->value;
  left->value = curr->value;
  curr->value = nCopyInteger;

  // сохранение Current
  IntList *pOldCurrent = curr;

  // рекурсия
  curr = curr->prev;
  if (curr != NULL) {
    if ((left->prev != curr) && (curr->next != left))
      QuickSortList(left, curr);
  }

  curr = pOldCurrent;
  curr = curr->next;
  if (curr != NULL) {
    if ((curr->prev != right) && (right->next != curr))
      QuickSortList(curr, right);
  }
}

int test() {

  AddListItem(100);
  AddListItem(12);
  AddListItem(56);
  AddListItem(3);
  AddListItem(2);
  AddListItem(1);
  AddListItem(67);

  PrintList();
  QuickSortList(g_First, g_Last);
  PrintList();
  RemoveAllItems();
  return 1;
}

}  // namespace qsort_2linked_list

#endif /* QUICKSORT_2LINKED_LIST_H_ */
