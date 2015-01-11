/*
 * 4_8_tree_match_subtree.h
 *
 *  Created on: 04 џэт. 2015 у.
 *      Author: andy
 */

#ifndef _TREE_MATCH_SUBTREE_H_
#define _TREE_MATCH_SUBTREE_H_

namespace tree_metch_subtree {

The code below implements this algorithm.
I boolean containsTree(TreeNode tl, TreeNode t2) {
if (t2 == null) { // The empty tree is always a subtree
3 return truej
4 }
return subTree(tl, t2);
6 }
7
8 boolean subTree(TreeNode rl, TreeNode r2) {
9 if (rl == null) {
18 return false; II big tree empty & subtree still not found.
II }
12 if (rl.data == r2.data) {
13 if (matchTree(rl,r2)) return true;
14 }
15 return (subTree(rl.left, r2) || subTree(rl.right, r2));
16 }
17
18 boolean matchTree(TreeNode rl, TreeNode r2) {
19 if (r2 == null && rl == null) // if both are empty
20 return true; // nothing left in the subtree
21
22 // if one, but not both, are empty
23 if (rl == null || r2 == null) {
24 return false;
25 }
26
27 if (rl.data != r2.data)
28 return false; // data doesn't match
29 return (matchTree(rl.leftJ r2.1eft) &&
36 matchTree(rl.right, r2.right));
31 }
32 }

}




#endif /* 4_8_TREE_MATCH_SUBTREE_H_ */
