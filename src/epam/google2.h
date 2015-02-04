/*
 * google2.h
 *
 *  Created on: 03 февр. 2015 г.
 *      Author: andy
 */

#ifndef GOOGLE2_H_
#define GOOGLE2_H_

//Given a binary tree, print the nodes out grouping by level
//
// a
///  \
//b  d
//\
//c
//
//a
//bd
//c


void swapQueWithSrc(std::queue<TreeNode*>& dest, std::queue<TreeNode*>& src) {
   dest.clear();
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
         std::cout << currentNode->data << У У;
         nextLevel.push(currenttNode->left);
         nextLevel.push(currenttNode->right);
       }
       if (currentLevel.empty()) {
          std::cout << С\nТ;
          swapQueWithSrc(currentLevel, nextLevel);
       }
   }
}


#endif /* GOOGLE2_H_ */
