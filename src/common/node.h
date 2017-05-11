/*
 * node.h
 *
 *  Created on: May 10, 2017
 *      Author: andy
 */

#ifndef SRC_COMMON_NODE_H_
#define SRC_COMMON_NODE_H_

// single linked list
// forward declarations
struct Node;
void print_nodes(Node* node);
void fill_nodes_from_array(Node& node, int arr[], int length);

// implementation
struct Node {
  Node(): val(0), next(0) {}
  Node(int v, Node* n = 0) : val(v), next(n) {}

  int val;
  Node *next;
};

void print_nodes(Node* node) {
  Node * n = node;
  while (n != 0) {
    std::cout << n->val << " ";
    n = n->next;
  }
  std::endl(std::cout);
}

void fill_nodes_from_array(Node& node, int arr[], int length) {
  node.val = arr[0];
  Node * n = &node;
  for (int i = 1; i < length; ++i) {
    Node* temp = new Node();
    temp->val = arr[i];
    n->next = temp;
    n = temp;
  }
}



#endif /* SRC_COMMON_NODE_H_ */
