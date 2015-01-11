/*
 * node.h
 *
 *  Created on: 10 џэт. 2015 у.
 *      Author: andy
 */

#ifndef NODE_H_
#define NODE_H_

template<typename T>
struct Node {
  Node(T val): data(val), next(0) {}
  T data;
  Node* next;
};



#endif /* NODE_H_ */
