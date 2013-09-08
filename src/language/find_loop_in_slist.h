//Given the root node to a singly linked list,
//write an algorithm to see if it loops back
//on itself somewhere in the middle.
#pragma once
#include <iostream>
#define LIST_LENGTH 20

namespace loop_list_test {
class SList {
  public:
    SList(int i) {
      data = i;
      next = NULL;

    }

  public:
    int data;
    SList * next;
};

bool FindLoopInList(SList * startNode) {
  SList *head = startNode;
  if (head != NULL) {
    SList *fastPtr = head;
    SList *slowPtr = head;

    bool isCircular = true;

    do {
      if (fastPtr->next == NULL || fastPtr->next->next == NULL) //SList end found
      {
        isCircular = false;
        break;
      }

      fastPtr = fastPtr->next->next;
      slowPtr = slowPtr->next;
    } while (fastPtr != slowPtr);

    if (isCircular)
      std::cout << " the list has loop" << std::endl;
    else
      std::cout << " the list has no loops" << std::endl;
    return isCircular;

  }
  std::cout << " the list is empty" << std::endl;
  return false;

}

}
