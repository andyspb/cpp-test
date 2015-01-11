/*
 * 4_7_find_first_common_ancestor.h
 *
 *  Created on: 04 џэт. 2015 у.
 *      Author: andy
 */

#ifndef _FIND_FIRST_COMMON_ANCESTOR_H_
#define _FIND_FIRST_COMMON_ANCESTOR_H_

namespace find_common_ancestro {


// Solution #2: Without Links to Parents
//Alternatively, you could follow a chain in which p and q are on the same side. That is, if
//pand q are both on the left of the node, branch left to look for the common ancestor. If
//they are both on the right, branch right to look for the common ancestor. When p and q
//are no longer on the same side, you must have found the first common ancestor.
The code below implements this approach.
1 /* Returns true if p is a descendent of root */
2 boolean covers(TreeNode root, TreeNode p) {
3 if (root == null) return false;
4 if (root == p) return true;
5 return covers(root.left, p) || covers(root.right, p);
6 }
7
8 TreeNode commonAncestorHelper(TreeNode root, TreeNode p,
9 TreeNode q) {
10 if (root == null) return null;
11 if (root == p M root == q) return root;
12
13 boolean is_p_on_left = covers(root.left, p);
14 boolean is_q_on_left = covers(root.left, q);
15
16 /* If p and q are on different sides, return root. */
17 if (is_p_on_left != is_q_on_left) return root;
18
19 /* Else, they are on the same side. Traverse this side. */
28 TreeNode child_side = is_p_on_left ? root.left : root.right;
21 return commonAncestorHelper(child_side, p, q);
22 }
23
24 TreeNode commonAncestor(TreeNode root, TreeNode p, TreeNode q) {
if (!covers(root, p) || !covers(root, q)) { // Error check
26 return null;
}
28 return commonAncestorHelper(root, p, q);
29 }

}



#endif /* 4_7_FIND_FIRST_COMMON_ANCESTOR_H_ */
