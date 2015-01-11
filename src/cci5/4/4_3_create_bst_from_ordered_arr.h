/*
 * 4_3_create_bst_from_ordered_arr.h
 *
 *  Created on: 04 џэт. 2015 у.
 *      Author: andy
 */

#ifndef CREATE_BST_FROM_ORDERED_ARR_H_
#define CREATE_BST_FROM_ORDERED_ARR_H_

namespace create_bst_from_array {

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

TreeNode* createMinimalBST(int arr[], int start, int end) {
  if (end < start) {
    return 0;
  }
  int mid = (start + end) / 2;
  TreeNode* n = new TreeNode(arr[mid]);
  n->left = createMinimalBST(arr, start, mid - 1);
  n->right = createMinimalBST(arr, mid + 1, end);
  return n;
}

TreeNode* createMinimalBST(int array[], int size) {
  return createMinimalBST(array, 0, size - 1);
}

}  // namespace create_bst_from_array

#endif /* CREATE_BST_FROM_ORDERED_ARR_H_ */
