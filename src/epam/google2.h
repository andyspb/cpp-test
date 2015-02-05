/*
 * google2.h
 *
 *  Created on: 03 ����. 2015 �.
 *      Author: andy
 */

#ifndef GOOGLE2_H_
#define GOOGLE2_H_

#include <queue>

namespace google_2 {

struct TreeNode {
  int data;
  TreeNode* left;
  TreeNode* right;

};


/*
Given a binary tree, print the nodes out grouping by level

   a
  /  \
  b  d
  \
   c

a
bd
c
*/

void swapQueWithSrc(std::queue<TreeNode*>& dest, std::queue<TreeNode*>& src) {
//  std::queue<TreeNode*> empty;
//  std::swap(dest, empty);
//  dest = {};
  // dest is empty

  while(!src.empty()) {
    TreeNode* treeNode = src.front();
    dest.push(treeNode);
    src.pop();
  }
}

void printLevelOrder(TreeNode* root) {
   if (!root) {
     return;
   }
   std::queue<TreeNode*> currentLevel, nextLevel;
   currentLevel.push(root);
   while(!currentLevel.empty()) {
       TreeNode* currentNode = currentLevel.front();
       currentLevel.pop();
       if (currentNode) {
         std::cout << currentNode->data << " ";
         nextLevel.push(currentNode->left);
         nextLevel.push(currentNode->right);
       }
       if (currentLevel.empty()) {
          std::cout << '\n';
          swapQueWithSrc(currentLevel, nextLevel);
       }
   }
}

} // namespace google_2
#endif /* GOOGLE2_H_ */
