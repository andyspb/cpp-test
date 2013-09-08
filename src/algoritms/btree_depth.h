#ifndef _BTREE_DEPTH_H
#define _BTREE_DEPTH_H

#include <iostream>
//Write a function to find the depth of a binary tree. Write a function to find the depth of a binary tree.

namespace btree_depth {
struct BTNode {
  BTNode(int i)
      : data(i),
        left(0),
        right(0) {
  }
  int data;
  BTNode * left;
  BTNode * right;
};
int btree_data = 0;

void fill_tree(BTNode *root, int& number) {
  if (!root || number == 0)
    return;

  BTNode * tmp = root;
  while (number != 0) {
    BTNode * leftNode = new BTNode(++btree_data);
    BTNode * rightNode = new BTNode(++btree_data);
    tmp->left = leftNode;
    tmp->right = rightNode;
    number -= 1;
    fill_tree(leftNode, number);
    fill_tree(rightNode, number);
  }
}

int btree_depth(BTNode *p) {
  if (!p)
    return 0;

  int h1 = 0, h2 = 0;
  if (p->left) {
    h1 = btree_depth(p->left);
  }
  if (p->right) {
    h2 = btree_depth(p->right);
  }

  return (h1 > h2 ? h1 + 1 : h2 + 1);
}

int test() {
  std::cout << "Tests: binary tree depth" << std::endl;
  BTNode *root = new BTNode(0);
  int elements = 3;
  fill_tree(root, elements);
  int depth = btree_depth(root);
  std::cout << "BTree with " << elements << " elements depth is " << depth
            << std::endl;
  std::cout << "<--- passed" << std::endl;
  return 1;
}
}  // namespace btree_depth

#endif //_BTREE_DEPTH_H
