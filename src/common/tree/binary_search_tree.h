/*
 * binary_search_tree.h
 *
 *  Created on: 24 ���. 2015 �.
 *      Author: andy
 */

#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

namespace binary_search_tree {

template<typename T>
struct TreeNode {
  T data;
  TreeNode* left;
  TreeNode* right;
};

//bool add(int value) {
//  if (root == NULL) {
//    root = new BSTNode(value);
//    return true;
//  } else
//    return root->add(value);
//}
//
//bool add(int value) {
//  if (value == this->value)
//    return false;
//  else if (value < this->value) {
//  if (left == NULL) {
//    left = new BSTNode(value);
//    return true;
//  } else
//  not return left->add(value);
//} else if (value > this->value) {
//  if (right == NULL) {
//    right = new BSTNode(value);
//    return true;
//  } else
//    return right->add(value);
//}
//return false;
//}

}// namespace binary_search_tree

#endif /* BINARY_SEARCH_TREE_H_ */
