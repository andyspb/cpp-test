/*
 * binary_tree.h
 *
 *  Created on: 15 дек. 2013 г.
 *      Author: andy
 */

#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include <iostream>

namespace binary_tree {

template<class T>
struct Node {
  Node(T v)
      : value(v),
        left(0),
        right(0) {
  }
  Node()
      : value(0),
        left(0),
        right(0) {
  }
  T value;
  Node<T> *left;
  Node<T> *right;
};

template<typename T>
void preorder_traverse(Node<T>*& node) {
  if (!node) {
    return;
  }
  std::cout << node->value << ' ';
  preorder_traverse(node->left);
  preorder_traverse(node->right);
}

template<typename T>
void inorder_traverse(Node<T>*& node) {
  if (!node) {
    return;
  }
  inorder_traverse(node->left);
  std::cout << node->value << ' ';
  inorder_traverse(node->right);
}

template<typename T>
void postorder_traverse(Node<T>*& node) {
  if (!node) {
    return;
  }
  postorder_traverse(node->left);
  postorder_traverse(node->right);
  std::cout << node->value << ' ';
}

template<typename T>
void breadth_first_traverse(Node<T>* node) {
  if (!node) {
    return;
  }
  std::queue<Node<T>*> que;
  que.push(node);
  Node<T>* n(0);
  while (!que.empty()) {
    n = (Node<T>*) que.front();
    std::cout << n->value << " ";
    que.pop();
    if (n->left) {
      que.push(n->left);
    }
    if (n->right) {
      que.push(n->right);
    }
  }
}

template<typename T>
void fill_tree(Node<T>* tree) {

  Node<int> * left = new Node<int>(2);
  Node<int> * right = new Node<int>(3);
  tree->left = left;
  tree->right = right;

  Node<int> * left1 = new Node<int>(4);
  Node<int> * right1 = new Node<int>(5);
  Node<int> * left2 = new Node<int>(6);
  Node<int> * right2 = new Node<int>(7);
  left->left = left1;
  left->right = right1;

  right->left = left2;
  right->right = right2;
}

int test() {
  std::cout << "Test: tree traversal --->" << std::endl;
  Node<int> *tree = new Node<int>(1);
  fill_tree(tree);

  std::cout << "\tpreorder traverse: ";
  preorder_traverse(tree);
  std::endl(std::cout);
  std::cout << "\tinorder traverse: ";
  inorder_traverse(tree);
  std::endl(std::cout);
  std::cout << "\tpostorder traverse: ";
  postorder_traverse(tree);
  std::endl(std::cout);

  std::cout << "\tbreadth traverse: ";
  breadth_first_traverse(tree);
  std::endl(std::cout);

  std::cout << "<--- tree traversal tests passed" << std::endl;
  return 1;
}
}

#endif /* BINARY_TREE_H_ */
