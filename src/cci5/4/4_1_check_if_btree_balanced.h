/*
 * 4_1_check_if_btree_balanced.h
 *
 *  Created on: 04 џэт. 2015 у.
 *      Author: andy
 */

#ifndef _CHECK_IF_BTREE_BALANCED_H_
#define _CHECK_IF_BTREE_BALANCED_H_

#include <iostream>     // std::cout#include <algorithm>    // std::max

namespace check_if_btree_balanced {
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int v)
      : val(v),
        left(0),
        right(0) {
  }
  ;
};

//1st -----------------------------------------------------------------
int getHeight(TreeNode* node) {
  if (!node)
    return 0;
  else
    return std::max(getHeight(node->left), getHeight(node->right)) + 1;
}

bool isBalanced_recursive(TreeNode * node) {
  if (!node)
    return true;
  int diff = getHeight(node->left) - getHeight(node->right);
  if (std::abs(diff) > 1) {
    return false;
  } else {
    return isBalanced(node->left) && isBalanced(node->right);
  }
}

//1st -----------------------------------------------------------------
int checkHeight(TreeNode* root) {
  if (root == NULL) {
    return 0;  // Height of 0
  }

  int leftHeight = checkHeight(root->left);
  if (leftHeight == -1) {
    return -1;  // Not balanced
  }

  int rightHeight = checkHeight(root->right);
  if (rightHeight == -1) {
    return -1;  // Not balanced
  }

  /* Check if current node is balanced. */
  int heightDiff = leftHeight - rightHeight;
  if (std::abs(heightDiff) > 1) {
    return -1;  // Not balanced
  } else {
    /* Return height */
    return std::max(leftHeight, rightHeight) + 1;
  }
}

bool isBalanced(TreeNode* root) {
  if (checkHeight(root) == -1) {
    return false;
  } else {
    return true;
  }
}

int test() {
  return 1;
}
}  // namespace check_if_btree_balanced

#endif /* _CHECK_IF_BTREE_BALANCED_H_ */
