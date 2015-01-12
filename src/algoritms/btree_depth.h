#ifndef _BTREE_DEPTH_H
#define _BTREE_DEPTH_H

#include "../logger/logger.h"

#include <iostream>
//Write a function to find the depth of a binary tree. Write a function to find the depth of a binary tree.

namespace btree_depth {
template<typename T>
struct BinaryTreeNode {
  BinaryTreeNode(T i)
      : data(i),
        left(0),
        right(0) {
  }
  int data;
  BinaryTreeNode * left;
  BinaryTreeNode * right;
};
int btree_data = 0;

template<typename T>
void fill_tree(BinaryTreeNode<T> *root, T& number) {
  if (!root || number == 0)
    return;

  BinaryTreeNode<T> * tmp = root;
  while (number != 0) {
    BinaryTreeNode<T> * leftNode = new BinaryTreeNode<T>(++btree_data);
    BinaryTreeNode<T> * rightNode = new BinaryTreeNode<T>(++btree_data);
    tmp->left = leftNode;
    tmp->right = rightNode;
    number -= 1;
    fill_tree<T>(leftNode, number);
    fill_tree<T>(rightNode, number);
  }
}

template<typename T>
int btree_depth(BinaryTreeNode<T> *node) {
  if (!node)
    return 0;

  int h1 = 0, h2 = 0;
  if (node->left) {
    h1 = btree_depth(node->left);
  }
  if (node->right) {
    h2 = btree_depth(node->right);
  }

  return (h1 > h2 ? h1 + 1 : h2 + 1);
}

int test() {
  logger::LogMethodWrapper l("Tests: binary tree depth");
  BinaryTreeNode<int> *root = new BinaryTreeNode<int>(0);
  int elements = 3;
  fill_tree<int>(root, elements);
  int depth = btree_depth<int>(root);
  std::cout << "\t\tBTree with " << elements << " elements depth is " << depth
            << std::endl;
  return 1;
}
}  // namespace btree_depth

#endif //_BTREE_DEPTH_H
