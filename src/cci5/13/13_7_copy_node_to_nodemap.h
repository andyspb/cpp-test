/*
 * 13_7_copy_node_to_nodemap.h
 *
 *  Created on: 05 џэт. 2015 у.
 *      Author: andy
 */

#ifndef _COPY_NODE_TO_NODEMAP_H_
#define _COPY_NODE_TO_NODEMAP_H_

#include <map>

namespace copy_node_2_nodemap {

struct Node {
  Node* ptr1;
  Node* ptr2;
};

typedef std::map<Node*, Node*> NodeMap;

Node * copy_recursive(Node * cur, NodeMap & nodeMap) {
  if (!cur) {
    return 0;
  }

  NodeMap::iterator i = nodeMap.find(cur);
  if (i != nodeMap.end()) {
    // we've been here before., return the copy
    return i->second;
  }

  Node * node = new Node;
  nodeMap[cur] = node;  // map current before traversing links
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

}  // namespace copy_node_2_nodemap

#endif /* _7_COPY_NODE_TO_NODEMAP_H_ */
