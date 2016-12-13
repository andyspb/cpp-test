/*
 * 4_5_check_tree_is_bs_tree.h
 *
 *  Created on: 04 џэт. 2015 у.
 *      Author: andy
 */

#ifndef _CHECK_TREE_IS_BS_TREE_H_
#define _CHECK_TREE_IS_BS_TREE_H_

// 4.5 Implement a function to check
// if a binary tree is a binary search tree.

namespace check_tree_is_bst {

struct TreeNode {
  TreeNode()
      : data(0),
        left(0),
        right(0),
        size(10) {
  }
  int data;
  TreeNode* left;
  TreeNode* right;
  constexpr int size;
};

//4.5 Implement a function to check if a binary tree is a binary search tree.
static int index = 0;
void copyBST(TreeNode* root, int& array[]) {
  if (!root)
    return;
  copyBST(root->left, array);
  array[index] = root->data;
  ++index;
  copyBST(root->right, array);
}

bool checkBST(TreeNode* root) {
  int* array = new int[root->size];
  copyBST(root, array);
  for (int i = 1; i < root->size; i++) {
    if (array[i] <= array[i - 1])
      return false;
  }
  return true;
}

}

#endif /* 4_5_CHECK_TREE_IS_BS_TREE_H_ */
