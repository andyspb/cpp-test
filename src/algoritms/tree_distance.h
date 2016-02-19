/*
 * tree_distance.h
 *
 *  Created on: Feb 18, 2016
 *      Author: andy
 */

#ifndef SRC_ALGORITMS_TREE_DISTANCE_H_
#define SRC_ALGORITMS_TREE_DISTANCE_H_

// Given a list o unique integers, first construct a binary search tree by inserting each integer in
// the order provided, then print the distance between two nodes A and B . We define distance as the number of edges
// on the path (traversing each edge only once) between nodes

// Input format
// The first line will contain A, the value of the firat node
// The second line will contain B, the value of the second node
// the third line will contain an integer N, the nuber of nodes in the tree
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
TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;
  RETURN_OK();
}
}  // namespace tree_distance

#endif /* SRC_ALGORITMS_TREE_DISTANCE_H_ */
