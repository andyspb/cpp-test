/*
 * duplicate_linkedlist.h
 *
 *  Created on: May 8, 2017
 *      Author: andy
 */

#ifndef SRC_ALGORITMS_DUPLICATE_LINKEDLIST_H_
#define SRC_ALGORITMS_DUPLICATE_LINKEDLIST_H_

#include "../common/common.h"
#include "../common/node.h"

namespace duplicate_linkedlist {

void fill_slist(Node& node, int arr[], int length) {
  node.val = arr[0];
  Node * l1 = &node;
  for (int i = 1; i < length; ++i) {
    Node* l = new Node();
    l->val = arr[i];
    l1->next = l;
    l1 = l;
  }
}

void print_slist(Node* list) {
  Node * l1 = list;
  while (l1 != NULL) {
    std::cout << l1->val << " ";
    l1 = l1->next;
  }
  std::endl(std::cout);
}

TEST_RESULT test() {
  __SCOPE_LOG__;
  Node l1, l2;
  int arr1[] = { 1, 2, 3, 4, 5 };
  int arr2[] = { 1, 2, 3, 4, 5, 6 };
  fill_slist(l1, arr1, sizeof_array(arr1));

  fill_slist(l2, arr2, sizeof_array(arr2));

  RETURN_OK();
}

}  // namespace duplicate_linkedlist

#endif /* SRC_ALGORITMS_DUPLICATE_LINKEDLIST_H_ */
