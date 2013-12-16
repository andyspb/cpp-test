/*
 * node_with_optional_ptr_to_another_list.h
 *
 *  Created on: 15 дек. 2013 г.
 *      Author: andy
 */

#ifndef NODE_WITH_OPTIONAL_PTR_TO_ANOTHER_LIST_H_
#define NODE_WITH_OPTIONAL_PTR_TO_ANOTHER_LIST_H_

namespace node_with_optional_ptr_to_another_list {

template <typename T>
class Node {
  T value;
  Node<T>* next;
};

int test() {
  return 1;
}

}  // namespace node_with_optional_ptr_to_another_list



#endif /* NODE_WITH_OPTIONAL_PTR_TO_ANOTHER_LIST_H_ */
