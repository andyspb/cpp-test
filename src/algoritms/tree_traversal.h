#ifndef TREE_TESTS_H__
#define TREE_TESTS_H__

#include <iostream>
#include <stack>
#include <queue>
#include <assert.h>

namespace tree_traversal_tests {
//	Binary Tree
template<class T>
struct Node {
    Node(T val) : m_Value(val), m_pLeft(0), m_pRight(0) {}
    Node() : m_Value(0), m_pLeft(0), m_pRight(0) {}
    T m_Value;
    Node<T> *m_pLeft;
    Node<T> *m_pRight;
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
  std::cout << tree->m_Value << ' ';
  if (tree->m_pLeft) {
    preorder_traverse(tree->m_pLeft);
  }
  if (tree->m_pRight) {
    preorder_traverse(tree->m_pRight);
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
  if (tree->m_pLeft) {
    inorder_traverse(tree->m_pLeft);
  }
  std::cout << tree->m_Value << ' ';
  if (tree->m_pRight) {
    inorder_traverse(tree->m_pRight);
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
  if (tree->m_pLeft) {
    postorder_traverse(tree->m_pLeft);
  }
  if (tree->m_pRight) {
    postorder_traverse(tree->m_pRight);
  }
  std::cout << tree->m_Value << ' ';
}

// Breadth-first Traversal
template<typename T>
void breadth_first_traverse(Node<T>* tree) {
  if (!tree) {
    return;
  }
  // create a que tu push nodes
  std::queue<Node<T>*> que;
  que.push(tree);
  // traverse ptr to keep nodes
  Node<T>* traverse = 0;
  while (!que.empty()) {
    // take front element from que
    traverse = (Node<T>*) que.front();
    // print the element
    std::cout << traverse->m_Value << ' ';
    // remove the element from Q
    que.pop();
    // insert into que left and rigth leaves
    // if any
    if (traverse->m_pLeft) {
      que.push(traverse->m_pLeft);
    }
    if (traverse->m_pRight) {
      que.push(traverse->m_pRight);
    }
  }
}

template<typename T>
void fill_tree(Node<T>* tree) {

  Node<int> * left = new Node<int>(2);
  Node<int> * right = new Node<int>(3);
  tree->m_pLeft = left;
  tree->m_pRight = right;

  Node<int> * left1 = new Node<int>(4);
  Node<int> * right1 = new Node<int>(5);
  Node<int> * left2 = new Node<int>(6);
  Node<int> * right2 = new Node<int>(7);
  left->m_pLeft = left1;
  left->m_pRight = right1;

  right->m_pLeft = left2;
  right->m_pRight = right2;

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
}  // namespace tree_traversal_tests

#endif // TREE_TESTS_H__
