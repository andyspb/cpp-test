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

// http://codereview.stackexchange.com/questions/35656/printing-out-a-binary-tree-level-by-level
template<typename T>
struct TreeNode {
  enum ORDER{
    PREODER,
    INORDER,
    POSTRODER
  };

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
    return size(node->left) + size(node->right) +1 ;
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

  void prettyPrintTree(TreeNode<T>* node) {
    if (!node) {
      std::cout << "Tree is empty." << std::endl;
    }
    std::queue<TreeNode<T>*> que;
    que.push(node);
    TreeNode<T>* t;
    while (!que.empty()) {
      t = que.front();
      que.pop();

    }
  }

//  void printTree()
};

namespace binary_tree {
  int test() {

    return 1;
  }
}  // namespace binary_tree

#endif /* BINARY_TREE_H_ */
