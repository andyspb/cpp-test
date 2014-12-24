#ifndef TEST_4_1_H_
#define TEST_4_1_H_
// Implement a function to check if a tree is balanced.
// For the purposes of this question, a balanced tree
// is defined to be a tree such that no two leaf nodes
// differ in distance from the root by more than one

#include <iostream>

namespace test_4_1 {
template<typename T>
struct TreeNode {
  TreeNode(T i)
      : data(i), left(NULL), right(NULL) {
  }
  ~TreeNode() {
    if (left) {
      delete left;
    }
    if (right) {
      delete right;
    }
  }
  T data;
  TreeNode * left;
  TreeNode * right;
};

template<typename T>
int maxDepth(TreeNode<T>* node) {
  return 1;
}

template<typename T>
int minDepth(TreeNode<T>* node) {
  return 1;
}

template<typename T>
bool isBalanced(TreeNode<T>* root) {
  return (maxDepth(root) - minDepth(root) <= 1);
}

int test() {
  std::cout << "Test 4_1: check if tree is balansed" << std::endl;
  TreeNode<int> node(0);
  return 1;
}
}  // namespace test_4_1

#endif /* TEST_4_1_H_ */
