/*
 * bplustree.h
 *
 *  Created on: Aug 27, 2015
 *      Author: andy
 */

#ifndef SRC_COMMON_BPLUSTREE_H_
#define SRC_COMMON_BPLUSTREE_H_

#include <iostream>

#include "../logger/logger.h"
#include "constants.h"


namespace bplus_tree {

class BTreeNode {
  int *keys;  // An array of keys
  int min_degree;      // Minimum degree (defines the range for number of keys)
  BTreeNode **child_ptrs;  // An array of child pointers
  int num_keys;     // Current number of keys
  bool is_leaf;  // Is true when node is is_leaf. Otherwise false

 public:
  BTreeNode(int _t, bool _leaf);   // Constructor

  // A utility function to insert a new key in the subtree rooted with
  // this node. The assumption is, the node must be non-full when this
  // function is called
  void insertNonFull(int k);

  // A utility function to split the child y of this node. i is index of y in
  // child array child_ptrs[].  The Child y must be full when this function is called
  void splitChild(int i, BTreeNode *tree_node);

  // A function to traverse all nodes in a subtree rooted with this node
  void traverse();

  // A function to search a key in subtree rooted with this node.
  BTreeNode *search(int k);   // returns NULL if k is not present.

  // Make BTree friend of this so that we can access private members of this
  // class in BTree functions
  friend class BTree;
};

// A BTree
class BTree {
  BTreeNode *root;  // Pointer to root node
  int t;  // Minimum degree
 public:
  // Constructor (Initializes tree as empty)
  BTree(int _t) {
    root = NULL;
    t = _t;
  }

  // function to traverse the tree
  void traverse() {
    if (root != NULL)
      root->traverse();
  }

  // function to search a key in this tree
  BTreeNode* search(int k) {
    return (root == NULL) ? NULL : root->search(k);
  }

  // The main function that inserts a new key in this B-Tree
  void insert(int k);
};

// Constructor for BTreeNode class
BTreeNode::BTreeNode(int t1, bool leaf1) {
  // Copy the given minimum degree and is_leaf property
  min_degree = t1;
  is_leaf = leaf1;

  // Allocate memory for maximum number of possible keys
  // and child pointers
  keys = new int[2 * min_degree - 1];
  child_ptrs = new BTreeNode *[2 * min_degree];

  // Initialize the number of keys as 0
  num_keys = 0;
}

// Function to traverse all nodes in a subtree rooted with this node
void BTreeNode::traverse() {
  // There are n keys and n+1 children, travers through n keys
  // and first n children
  int key;
  for (key = 0; key < num_keys; ++key) {
    // If this is not leaf, then before printing key[i],
    // traverse the subtree rooted with child C[i].
    if (!is_leaf)
      child_ptrs[key]->traverse();
    std::cout << " " << keys[key];
  }

  // Print the subtree rooted with last child
  if (!is_leaf)
    child_ptrs[key]->traverse();
}

// Function to search key k in subtree rooted with this node
BTreeNode *BTreeNode::search(int k) {
  // Find the first key greater than or equal to k
  int key = 0;
  while (key < num_keys && k > keys[key])
    ++key;

  // If the found key is equal to k, return this node
  if (keys[key] == k)
    return this;

  // If key is not found here and this is a leaf node
  if (is_leaf)
    return NULL;

  // Go to the appropriate child
  return child_ptrs[key]->search(k);
}

// The main function that inserts a new key in this B-Tree
void BTree::insert(int k) {
  // If tree is empty
  if (root == NULL) {
    // Allocate memory for root
    root = new BTreeNode(t, true);
    root->keys[0] = k;  // Insert key
    root->num_keys = 1;  // Update number of keys in root
  } else  // If tree is not empty
  {
    // If root is full, then tree grows in height
    if (root->num_keys == 2 * t - 1) {
      // Allocate memory for new root
      BTreeNode *treeNode = new BTreeNode(t, false);

      // Make old root as child of new root
      treeNode->child_ptrs[0] = root;

      // Split the old root and move 1 key to the new root
      treeNode->splitChild(0, root);

      // New root has two children now.  Decide which of the
      // two children is going to have new key
      int i = 0;
      if (treeNode->keys[0] < k)
        i++;
      treeNode->child_ptrs[i]->insertNonFull(k);

      // Change root
      root = treeNode;
    } else
      // If root is not full, call insertNonFull for root
      root->insertNonFull(k);
  }
}

// A utility function to insert a new key in this node
// The assumption is, the node must be non-full when this
// function is called
void BTreeNode::insertNonFull(int k) {
  // Initialize index as index of rightmost element
  int i = num_keys - 1;

  // If this is a leaf node
  if (is_leaf) {
    // The following loop does two things
    // a) Finds the location of new key to be inserted
    // b) Moves all greater keys to one place ahead
    while (i >= 0 && keys[i] > k) {
      keys[i + 1] = keys[i];
      i--;
    }

    // Insert the new key at found location
    keys[i + 1] = k;
    num_keys = num_keys + 1;
  } else  // If this node is not leaf
  {
    // Find the child which is going to have the new key
    while (i >= 0 && keys[i] > k)
      i--;

    // See if the found child is full
    if (child_ptrs[i + 1]->num_keys == 2 * min_degree - 1) {
      // If the child is full, then split it
      splitChild(i + 1, child_ptrs[i + 1]);

      // After split, the middle key of C[i] goes up and
      // C[i] is splitted into two.  See which of the two
      // is going to have the new key
      if (keys[i + 1] < k)
        i++;
    }
    child_ptrs[i + 1]->insertNonFull(k);
  }
}

// A utility function to split the child y of this node
// Note that y must be full when this function is called
void BTreeNode::splitChild(int i, BTreeNode *tree_node) {
  // Create a new node which is going to store (t-1) keys
  // of tree_node
  BTreeNode *z = new BTreeNode(tree_node->min_degree, tree_node->is_leaf);
  z->num_keys = min_degree - 1;

  // Copy the last (t-1) keys of tree_node to z
  for (int j = 0; j < min_degree - 1; j++)
    z->keys[j] = tree_node->keys[j + min_degree];

  // Copy the last t children of tree_node to z
  if (!tree_node->is_leaf) {
    for (int j = 0; j < min_degree; j++)
      z->child_ptrs[j] = tree_node->child_ptrs[j + min_degree];
  }

  // Reduce the number of keys in tree_node
  tree_node->num_keys = min_degree - 1;

  // Since this node is going to have a new child,
  // create space of new child
  for (int j = num_keys; j >= i + 1; j--)
    child_ptrs[j + 1] = child_ptrs[j];

  // Link the new child to this node
  child_ptrs[i + 1] = z;

  // A key of tree_node will move to this node. Find location of
  // new key and move all greater keys one space ahead
  for (int j = num_keys - 1; j >= i; j--)
    keys[j + 1] = keys[j];

  // Copy the middle key of tree_node to this node
  keys[i] = tree_node->keys[min_degree - 1];

  // Increment count of keys in this node
  num_keys = num_keys + 1;
}

// Driver program to test above functions
TEST_RESULT test() {
  __SCOPE_LOG__;
  BTree t(3);  // A B-Tree with minium degree 3
  t.insert(10);
  t.insert(20);
  t.insert(5);
  t.insert(6);
  t.insert(12);
  t.insert(30);
  t.insert(7);
  t.insert(17);

  std::cout << "Traversal of the constucted tree is ";
  t.traverse();

  int k = 6;
  (t.search(k) != NULL) ? std::cout << "\nPresent" : std::cout << "\nNot Present";

  k = 15;
  (t.search(k) != NULL) ? std::cout << "\nPresent" : std::cout << "\nNot Present";

  return 0;
}

}  // namespace bplus_tree

#endif /* SRC_COMMON_BPLUSTREE_H_ */
