/*
 * merge_sort_linked_list2.h
 *
 *  Created on: 16 θώνÿ 2015 γ.
 *      Author: andy
 */

#ifndef SRC_ALGORITMS_MERGE_SORT_LINKED_LIST2_H_
#define SRC_ALGORITMS_MERGE_SORT_LINKED_LIST2_H_

namespace merge_sort_linked_list2 {

struct ListNode {
  ListNode* next;
  int data;
};

node* MergeSort(node *my_node) {
  node *secondNode;

  if (my_node == NULL)
    return NULL;
  else if (my_node->next == NULL)
    return my_node;
  else {
    secondNode = Split(my_node);
    return Merge(MergeSort(my_node), MergeSort(secondNode));
  }
}

node* Merge(node* firstNode, node* secondNode) {
  if (firstNode == NULL)
    return secondNode;
  else if (secondNode == NULL)
    return firstNode;
  else if (firstNode->number <= secondNode->number)  //if I reverse the sign to >=, the behavior reverses
      {
    firstNode->next = Merge(firstNode->next, secondNode);
    return firstNode;
  } else {
    secondNode->next = Merge(firstNode, secondNode->next);
    return secondNode;
  }
}

node* Split(node* my_node) {
  node* secondNode;

  if (my_node == NULL)
    return NULL;
  else if (my_node->next == NULL)
    return NULL;
  else {
    secondNode = my_node->next;
    my_node->next = secondNode->next;
    secondNode->next = Split(secondNode->next);
    return secondNode;
  }
}

}  // merge_sort_linked_list2

#endif /* SRC_ALGORITMS_MERGE_SORT_LINKED_LIST2_H_ */
