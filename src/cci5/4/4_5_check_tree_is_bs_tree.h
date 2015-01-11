/*
 * 4_5_check_tree_is_bs_tree.h
 *
 *  Created on: 04 џэт. 2015 у.
 *      Author: andy
 */

#ifndef _CHECK_TREE_IS_BS_TREE_H_
#define _CHECK_TREE_IS_BS_TREE_H_


// 4.5 Imp/emen t a function to check if a binary tree is a binary search tree.

namespace check_tree_is_bst {

//4.5 Imp/emen t a function to check if a binary tree is a binary search tree.
1 public static int index = 0;
 public static void copyBST(TreeNode root, int[] array) {
 3 if (root == null) return;
 4 copyBST(root.left, array);
 array[index] = root.data;
 6 index++;
 copyBST(root.right, array);
 8 }
 9
 10 public static boolean checkBST(TreeNode root) {
 11 int[] array = new int[root.size];
 12 copyBST(root, array);
 13 for (int i = 1; i < array.length; i++) {
 14 if (array[i] <= array[i - 1]) return false;
 15 }
 16 return true;
 17 }

}





#endif /* 4_5_CHECK_TREE_IS_BS_TREE_H_ */
