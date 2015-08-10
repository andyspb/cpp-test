/*
 * check_tree_is_bst.h
 *
 *  Created on: 26 џэт. 2015 у.
 *      Author: andy
 */

#ifndef CHECK_TREE_IS_BST_H_
#define CHECK_TREE_IS_BST_H_

struct node {
  node * left;
  node * right;
  int data;
};

namespace check_tree_is_bst {
TEST_RESULT test(struct node* node) {
  if (!node)
    return 1;

  /* false if left is > than node */
  if (!node->left && node->left->data > node->data)
    return 0;

  /* false if right is < than node */
  if (!node->right && node->right->data < node->data)
    return 0;

  /* false if, recursively, the left or right is not a BST */
  if (!isBST(node->left) || !isBST(node->right))
    return 0;

  /* passing all that, it's a BST */
  return 1;
}
}  // namespace check_tree_is_bst

#endif /* CHECK_TREE_IS_BST_H_ */
