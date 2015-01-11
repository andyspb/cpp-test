/*
 * 4_6_find_next_node_of_given.h
 *
 *  Created on: 04 џэт. 2015 у.
 *      Author: andy
 */

#ifndef _FIND_NEXT_NODE_OF_GIVEN_H_
#define _FIND_NEXT_NODE_OF_GIVEN_H_

//4.6 Write an algorithm to find the 'next'node (i.e., in-order successor) of a given node in
//a binary search tree. You may assume that each node has a link to its parent.

namespace find_next_node_of_given {

public TreeNode inorderSucc(TreeNode n) {
if (n == null) return null;
3
/* Found right children -> return leftmost node of right
5 * subtree. */
6 if (n.right != null) {
return leftMostChild(n.right);
} else {
9 TreeNode q = n;
10 TreeNode x = q.parent;
II // Go up until we're on left instead of right
12 while (x != null && x.left != q) {
q = x;
14 x = x.parent;
15 }
16 return x;
17 }
18 }
19
20 public TreeNode leftMostChild(TreeNode n) {
21 if (n == null) {
22 return null;
23 }
24 while (n.left != null) {
25 n = n.left;
}
27 return n;
28 }

#endif /* _FIND_NEXT_NODE_OF_GIVEN_H_ */
