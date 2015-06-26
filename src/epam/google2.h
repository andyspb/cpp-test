/*
 * google2.h
 *
 *  Created on: 03 ����. 2015 �.
 *      Author: andy
 */

#ifndef GOOGLE2_H_
#define GOOGLE2_H_

#include <queue>
#include <iostream>

namespace google_2 {

struct TreeNode {
  TreeNode()
      : data(0),
        left(0),
        right(0) {
  }
  TreeNode(int d)
      : data(d),
        left(0),
        right(0) {
  }
  int data;
  TreeNode* left;
  TreeNode* right;
};

/*
 Given a binary tree, print the nodes out grouping by level

 a
 /  \
  b  d
 c

 a
 bd
 c
 */

void swapEmptyQueWithSrc(std::queue<TreeNode*>& dest,
                         std::queue<TreeNode*>& src) {
  if (!dest.empty()) {
    dest = std::queue<TreeNode*>();
  }

  while (!src.empty()) {
    TreeNode* node = src.front();
    dest.push(node);
    src.pop();
  }
}

void printLevelOrder(TreeNode* root) {
  if (!root) {
    return;
  }
  ::std::queue<TreeNode*> curr_level, next_level;
  curr_level.push(root);
  while(!curr_level.empty()){
    TreeNode* curr_node = curr_level.front();
    curr_level.pop();
    if (curr_node) {
      ::std::cout << curr_node->data << " ";
      next_level.push(curr_node->left);
      next_level.push(curr_node->right);
    }
    if (curr_level.empty()) {
      ::std::cout << ::std::endl;
      swapEmptyQueWithSrc(curr_level, next_level);
    }
  }

//  std::queue<TreeNode*> currentLevel, nextLevel;
//  currentLevel.push(root);
//  while (!currentLevel.empty()) {
//    TreeNode* currentNode = currentLevel.front();
//    currentLevel.pop();
//    if (currentNode) {
//      std::cout << currentNode->data << " ";
//      nextLevel.push(currentNode->left);
//      nextLevel.push(currentNode->right);
//    }
//    if (currentLevel.empty()) {
//      std::cout << '\n';
//      swapEmptyQueWithSrc(currentLevel, nextLevel);
//    }
//  }
}

int test() {
  std::cout << "Test print tree in level order:\n";
  TreeNode t1;
  t1.data = 1;
  TreeNode t2;
  t2.data = 2;
  TreeNode t3;
  t3.data = 3;
  TreeNode t4;
  t4.data = 4;
  TreeNode t5;
  t5.data = 5;
  TreeNode t6;
  t6.data = 6;

  t1.left = &t2;
  t1.right = &t3;

  t2.left = &t4;
  t2.right = &t5;

  t3.left = &t6;

  printLevelOrder(&t1);

  return 1;
}

}  // namespace google_2
#endif /* GOOGLE2_H_ */
