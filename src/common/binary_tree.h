/*
 * binary_tree.h
 *
 *  Created on: Jan 13, 2015
 *      Author: andy
 */

#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include <iostream>

#include <queue>
#include <algorithm>

namespace binary_tree {

enum ORDER {
  PREODER,
  INORDER,
  POSTRODER
};

// http://codereview.stackexchange.com/questions/35656/printing-out-a-binary-tree-level-by-level
template<typename T>
struct TreeNode {

  T data;
  TreeNode* left;
  TreeNode* right;

  TreeNode()
      : data(0),
        left(0),
        right(0) {
  }
  TreeNode(T d)
      : data(d),
        left(0),
        right(0) {
  }
  TreeNode(T d, TreeNode* l, TreeNode* r)
      : data(d),
        left(l),
        right(r) {
  }

  int depth(TreeNode* node) {
    if (!node)
      return 0;
    return std::max(depth(node->left), depth(node->right)) + 1;
  }

  int size(TreeNode* node) {
    if (!node)
      return 0;
    return size(node->left) + size(node->right) + 1;
  }

  bool isBST(TreeNode* node, int min, int max) {
    if (!node)
      return true;
    if (node->data < min || node->data > max)
      return false;
    return isBST(node->left, min, node->data)
        && isBST(node->right, node->data, max);
  }

  bool isBinarySearchTree(TreeNode* node, int min, int max) {

    if (!node) {
      return true;
    }

    bool left = isBinarySearchTree(node->left, min, node->data);
    bool right = isBinarySearchTree(node->right, node->data, max);

    return left && right && (node->data < max) && (node->data >= min);

  }

  TreeNode* insert(TreeNode* node, T data) {
    if (!node)
      return new TreeNode(data);
    if (data <= node->data)
      node->left = insert(node->left, data);
    else
      node->right = insert(node->right, data);
    return node;
  }

  void print(TreeNode* node, const ORDER& order) {
    if (!node)
      return;
    if (order == PREODER) {
      std::cout << node->data << " ";
    }
    print(node->left, order);
    if (order == INORDER) {
      std::cout << node->data << " ";
    }
    print(node->right, order);
    if (order == POSTRODER) {
      std::cout << node->data << " ";
    }
  }

  void printLevelOrder(TreeNode *root) {
    if (!root)
      return;
    std::queue<TreeNode*> currentLevel, nextLevel;
    currentLevel.push(root);
    while (!currentLevel.empty()) {
      TreeNode *currNode = currentLevel.front();
      currentLevel.pop();
      if (currNode) {
        std::cout << currNode->data << " ";
        nextLevel.push(currNode->left);
        nextLevel.push(currNode->right);
      }
      if (currentLevel.empty()) {
        std::cout << std::endl;
        swap(currentLevel, nextLevel);
      }
    }
  }

  void printLevelOrder2(TreeNode *root) {
    if (!root)
      return;
    std::queue<TreeNode*> nodesQueue;
    int nodesInCurrentLevel = 1;
    int nodesInNextLevel = 0;
    nodesQueue.push(root);
    while (!nodesQueue.empty()) {
      TreeNode *currNode = nodesQueue.front();
      nodesQueue.pop();
      nodesInCurrentLevel--;
      if (currNode) {
        std::cout << currNode->data << " ";
        nodesQueue.push(currNode->left);
        nodesQueue.push(currNode->right);
        nodesInNextLevel += 2;
      }
      if (nodesInCurrentLevel == 0) {
        std::cout << std::endl;
        nodesInCurrentLevel = nodesInNextLevel;
        nodesInNextLevel = 0;
      }
    }
  }
};

template<typename T>
void destroy(TreeNode<T> *node) {
  if (node) {
    destroy(node->left);
    destroy(node->right);
    delete node;
  }
}

int test() {
  std::cout << __PRETTY_FUNCTION__ << std::endl;

  TreeNode<int> t1(1);
  TreeNode<int> t2(2);
  TreeNode<int> t3(3);
  TreeNode<int> t4(4);
  TreeNode<int> t5(5);
  TreeNode<int> t6(6);
  TreeNode<int> t7(7);

  t1.left = &t2;
  t1.right = &t3;

  t2.left = &t4;
  t2.right = &t5;

  t3.left = &t6;
  t3.right = &t7;

  t1.print(&t1, binary_tree::PREODER);
  std::cout << std::endl;

  t1.printLevelOrder(&t1);
  std::cout << std::endl;

  t1.printLevelOrder2(&t1);
  std::cout << std::endl;

  std::cout << "isBST: " << t1.isBST(&t1, 0, 100);
  std::cout << std::endl;

//  destroy(&t1);
  return 1;
}
}  // namespace binary_tree

#endif /* BINARY_TREE_H_ */
