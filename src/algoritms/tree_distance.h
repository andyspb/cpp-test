/*
 * tree_distance.h
 *
 *  Created on: Feb 18, 2016
 *      Author: andy
 */

#ifndef SRC_ALGORITMS_TREE_DISTANCE_H_
#define SRC_ALGORITMS_TREE_DISTANCE_H_

// Given a list o unique integers, first construct a binary search tree by
// inserting each integer in the order provided, then print the distance
// between two nodes A and B. We define distance as the number of edges
// on the path (traversing each edge only once) between nodes

// Input format
// The first line will contain A, the value of the first node
// The second line will contain B, the value of the second node
// the third line will contain an integer N, the number of nodes in the tree
// the fourth node line will contain N integers, the node values

// Constraints
// All trees will have fewer than 2^20 nodes
// All values fall in the range [0, 2^32]

// Output format
// print a single integer, the distance between A and B
// if either A or B does not exists, print "Not found"

// Sample input
// 1
// 3
// 4
// 4 2 1 3

// Sample Output
// 2

namespace tree_distance {
struct node {
  int data;
  struct node *left;
  struct node *right;
};

// An utility function to create a node
struct node* newNode(int data) {
  struct node* temp = (struct node *) malloc(sizeof(struct node));
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;
}
TEST_RESULT test() {
  __SCOPE_LOG__;
  RETURN_OK();
}
}  // namespace tree_distance

#endif /* SRC_ALGORITMS_TREE_DISTANCE_H_ */
