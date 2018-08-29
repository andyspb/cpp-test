/*
 * node.h
 *
 *  Created on: May 8, 2017
 *      Author: andy
 */

#ifndef SRC_COMMON_TREE_NODE_H_
#define SRC_COMMON_TREE_NODE_H_

namespace tree {

struct node {
  int data;
  struct node *left;
  struct node *right;
}*root;

}  // namespace tree

#endif /* SRC_COMMON_TREE_NODE_H_ */
