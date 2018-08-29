#ifndef TREE_TRAVERSAL_H__
#define TREE_TRAVERSAL_H__

#include <iostream>
#include <stack>
#include <queue>
#include <assert.h>

namespace tree_traversal {
//	Binary Tree
template<class T>
struct Node {
  Node(T val)
      : value(val),
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

// Depth-first Traversal preorder
// To traverse a non-empty binary tree in preorder,
// perform the following operations recursively at each node,
// starting with the root node:
//  Visit the root.
//  Traverse the left subtree.
//  Traverse the right subtree.
template<typename T>
void preorder_traverse(Node<T>* tree) {
  if (!tree) {
    return;
  }
  std::cout << tree->value << ' ';
  if (tree->left) {
    preorder_traverse(tree->left);
  }
  if (tree->right) {
    preorder_traverse(tree->right);
  }
}

// inorder
// To traverse a non-empty binary tree in inorder (symmetric),
// perform the following operations recursively at each node:
// Traverse the left subtree.
// Visit the root.
// Traverse the right subtree.
template<typename T>
void inorder_traverse(Node<T>* tree) {
  if (!tree)
    return;
  if (tree->left) {
    inorder_traverse(tree->left);
  }
  std::cout << tree->value << ' ';
  if (tree->right) {
    inorder_traverse(tree->right);
  }
}

// postorder
// To traverse a non-empty binary tree in postorder,
// perform the following operations recursively at each node:
// Traverse the left subtree.
// Traverse the right subtree.
// Visit the root.
template<typename T>
void postorder_traverse(Node<T>* tree) {
  if (!tree)
    return;
  if (tree->left) {
    postorder_traverse(tree->left);
  }
  if (tree->right) {
    postorder_traverse(tree->right);
  }
  std::cout << tree->value << ' ';
}

// Breadth-first Traversal
template<typename T>
void breadth_first_traverse(Node<T>* node) {
  if (!node)
    return;
  std::queue<Node<T>*> que;
  que.push(node);
  Node<T>* t;
  while (!que.empty()) {
    t = que.front();
    std::cout << t->value << ' ';
    que.pop();
    if (t->left)
      que.push(t->left);
    if (t->right)
      que.push(t->right);
  }
  std::cout << std::endl;
}

// Level order tree traversal
template<typename T>
void breadth_back_traverse(Node<T>* node) {
  if (!node)
    return;
  std::queue<Node<T>*> que;
  std::stack<T> stack_;
  que.push(node);
  Node<T>* t;
  while (!que.empty()) {
    t = que.front();
    stack_.push(t->value);
    que.pop();
    if (t->left)
      que.push(t->left);
    if (t->right)
      que.push(t->right);
  }
  while (!stack_.empty()) {
    std::cout << stack_.top() << " ";
    stack_.pop();
  }
  std::cout << std::endl;
}

// PrintLevelOrder
template<typename T>
void print_level_order(Node<T>* root) {
  if (!root)
    return;
  std::queue<Node<T>*> current_level, next_level;
  current_level.push(root);
  while (!current_level.empty()) {
    Node<T>* node = current_level.front();
    current_level.pop();
    if (node) {
      std::cout << node->value;
      next_level.push(node->left);
      next_level.push(node->right);
    }
    if (current_level.empty()) {
      std::endl(std::cout);
      std::swap(current_level, next_level);
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

TEST_RESULT test() {
  __SCOPE_LOG__;
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

  std::cout << "\tbreadth first traverse: ";
  breadth_first_traverse(tree);
  //std::endl(std::cout);

  std::cout << "\tbreadth back traverse: ";
  breadth_back_traverse(tree);
  //std::endl(std::cout);

  std::cout << "\tprint level order:\n";
  print_level_order(tree);

  RETURN_OK();
}
}  // namespace tree_traversal_tests

#endif // TREE_TRAVERSAL_H__
