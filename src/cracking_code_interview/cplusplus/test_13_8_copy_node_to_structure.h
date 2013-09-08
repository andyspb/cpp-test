/*
 * test_13_8_copy_node_to_structure.h
 *
 *  Created on: 13.11.2012
 *      Author: andy
 */
// Write a method that takes a pointer to a Node structure
// as a parameter and returns a complete copy of the passed-in data structure.
// The Node structure contains two pointers to other Node structures.

#ifndef TEST_13_8_COPY_NODE_TO_STRUCTURE_H_
#define TEST_13_8_COPY_NODE_TO_STRUCTURE_H_

#include <map>

namespace test_13_8_copy_node_to_structure {

struct Node {
    Node* ptr1;
    Node* ptr2;
};

typedef std::map<Node*, Node*> NodeMap;

Node * copy_recursive(Node * cur, NodeMap & nodeMap) {
  if (cur == NULL) {
    return NULL;
  }
  NodeMap::iterator iter = nodeMap.find(cur);
  if (iter != nodeMap.end()) {
    // we’ve been here before, return the copy
    return iter->second;
  }
  Node * node = new Node;
  nodeMap[cur] = node;  // map current node before traversing links
  node->ptr1 = copy_recursive(cur->ptr1, nodeMap);
  node->ptr2 = copy_recursive(cur->ptr2, nodeMap);
  return node;
}
Node * copy_structure(Node * root) {
  NodeMap nodeMap;  // we will need an empty map
  return copy_recursive(root, nodeMap);
}

int test() {
  return 1;
}
}  // test_13_8_copy_node_to_structure

#endif /* TEST_13_8_COPY_NODE_TO_STRUCTURE_H_ */
