/*
 * 2_2_del_node_in_middle_with_access_the_node_only.h
 *
 *  Created on: 27 дек. 2014 г.
 *      Author: andy
 */

#ifndef DEL_NODE_IN_MIDDLE_WITH_ACCESS_THE_NODE_ONLY_H_
#define DEL_NODE_IN_MIDDLE_WITH_ACCESS_THE_NODE_ONLY_H_

namespace del_node_in_middle {

class Node {
 public:
  Node(int v)
      : value(v),
        next(NULL) {
  }
  ;
  int value;
  Node *next;
};

bool deleteNode(Node* node) {
  if (node == NULL || node->next == NULL) {
    return false;  // Failure
  }

  Node *next = node->next;
  node->value = next->value;
  node->next = next->next;

  return true;
}

}

#endif /* DEL_NODE_IN_MIDDLE_WITH_ACCESS_THE_NODE_ONLY_H_ */
