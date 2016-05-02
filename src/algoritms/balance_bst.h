/*
 * balance_bst.h
 *
 *  Created on: May 2, 2016
 *      Author: andy
 */

#ifndef SRC_ALGORITMS_BALANCE_BST_H_
#define SRC_ALGORITMS_BALANCE_BST_H_

#include <vector>

// Given a BST (Binary Search Tree) that may be unbalanced, convert it into a
// balanced BST that has minimum possible height.
// Input:
//           4
//         /   \
//        3     5
//       /       \
//      2         6
//     /           \
//    1             7
// Output:
//        4
//     /    \
//    2      6
//  /  \    /  \
// 1    3  5    7
namespace balance_bst {
struct Node {
  int data;
  Node* left, *right;
};

/* This function traverse the skewed binary tree and
 stores its nodes pointers in vector nodes[] */
void storeBSTNodes(Node* root, std::vector<Node*> &nodes) {
  // Base case
  if (root == NULL)
    return;

  // Store nodes in Inorder (which is sorted
  // order for BST)
  storeBSTNodes(root->left, nodes);
  nodes.push_back(root);
  storeBSTNodes(root->right, nodes);
}

/* Recursive function to construct binary tree */
Node* buildTreeUtil(std::vector<Node*> &nodes, int start, int end) {
  // base case
  if (start > end)
    return NULL;

  /* Get the middle element and make it root */
  int mid = (start + end) / 2;
  Node *root = nodes[mid];

  /* Using index in Inorder traversal, construct
   left and right subtress */
  root->left = buildTreeUtil(nodes, start, mid - 1);
  root->right = buildTreeUtil(nodes, mid + 1, end);

  return root;
}

// This functions converts an unbalanced BST to
// a balanced BST
Node* buildTree(Node* root) {
  // Store nodes of given BST in sorted order
  vector<Node *> nodes;
  storeBSTNodes(root, nodes);

  // Constucts BST from nodes[]
  int n = nodes.size();
  return buildTreeUtil(nodes, 0, n - 1);
}

// Utility function to create a new node
Node* newNode(int data) {
  Node* node = new Node;
  node->data = data;
  node->left = node->right = NULL;
  return (node);
}

/* Function to do preorder traversal of tree */
void preOrder(Node* node) {
  if (node == NULL)
    return;
  printf("%d ", node->data);
  preOrder(node->left);
  preOrder(node->right);
}

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;
  /* Constructed skewed binary tree is
                  10
                 /
                8
               /
              7
             /
            6
           /
          5   */

  Node* root = newNode(10);
  root->left = newNode(8);
  root->left->left = newNode(7);
  root->left->left->left = newNode(6);
  root->left->left->left->left = newNode(5);

  root = buildTree(root);

  printf("Preorder traversal of balanced "
         "BST is : \n");
  preOrder(root);

  RETURN_OK();
}

}  // namespace balance_bst



#endif /* SRC_ALGORITMS_BALANCE_BST_H_ */
