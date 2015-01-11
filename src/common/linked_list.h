/*
 * linked_list.h
 *
 *  Created on: 04 џэт. 2015 у.
 *      Author: andy
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

namespace linked_list {

template<typename T>
class SingleListNode {
  T data;
  SingleListNode *next;
};

template<typename T>
class DoubleLinkedList {
  T data;
  DoubleLinkedList * prev;
  DoubleLinkedList * next;
};


}  // namespace linked_list



#endif /* LINKED_LIST_H_ */
