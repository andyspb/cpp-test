/*
 * dlinked_list.h
 *
 *  Created on: May 8, 2017
 *      Author: andy
 */

#ifndef SRC_COMMON_LIST_NODE_H_
#define SRC_COMMON_LIST_NODE_H_

namespace list {

template<typename T=int>
class Node {
  T data;
  Node *next;
};

template<typename T>
class DNode {
  T data;
  DNode * prev;
  DNode * next;
};

template<>
class Node<int> {
  int data;
  Node *next;
};

}  // namespace list


#endif /* SRC_COMMON_LIST_NODE_H_ */
