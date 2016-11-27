/*
 * check_tree_is_bst.h
 *
 *  Created on: 26 ���. 2015 �.
 *      Author: andy
 */

#ifndef CHECK_TREE_IS_BST_H_
#define CHECK_TREE_IS_BST_H_

#include <iostream>
#include <iomanip>

namespace check_tree_is_bst {

struct Node {
  Node * left;
  Node * right;
  int data;

  Node(int value): left(0), right(0), data(value) {}
};

bool check_tree_is_bst(struct Node* node) {
  if (!node)
    return true;
  LOG(INFO) << "node data: " << node->data;

  /* false if left is > than node */
  if (node->left && node->left->data > node->data) {
      return false;
  }

  /* false if right is < than node */
  if (node->right && node->right->data < node->data) {
      return false;
  }

  /* false if, recursively, the left or right is not a BST */
  if (!check_tree_is_bst(node->left) || !check_tree_is_bst(node->right))
    return false;


  /* passing all that, it's a BST */
  return true;
}

TEST_RESULT test() {
  __SCOPE_LOG__;
  Node node(5);
  Node node1(3);
  Node node2(7);

  Node node11(2);
  Node node12(4);

  Node node21(6);
  Node node22(8);

  node.left = &node1;
  node.right = &node2;

  node1.left = &node11;
  node1.right = &node12;

  node2.left = &node21;
  node2.right = &node22;

  bool result = check_tree_is_bst(&node);

  LOG(INFO) << "check_tree_is_bst: " <<
      std::boolalpha << result;
  RETURN_OK();
}
}  // namespace check_tree_is_bst

#endif /* CHECK_TREE_IS_BST_H_ */
