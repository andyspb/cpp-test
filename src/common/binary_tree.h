/*
 * binary_tree.h
 *
 *  Created on: Jan 13, 2015
 *      Author: andy
 */

#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include <queue>
// http://codereview.stackexchange.com/questions/35656/printing-out-a-binary-tree-level-by-level
template<typename T>
class TreeNode {
 public:
  T data;
  TreeNode* left;
  TreeNode* right;

  TreeNode() : data(0), left(0), right(0) {}
  TreeNode(T d) : data(d), left(0), right(0) {}
  TreeNode(T d, TreeNode* l, TreeNode* r) : data(d), left(l), right(r) {}

  void pretty_print_tree(TreeNode<T>* node) {
    if (!node) {
      std::cout << "Tree is empty." << std::endl;
    }
    std::queue<TreeNode<T>*> que;
    que.push(node);
    TreeNode<T>* t;
    while (!que.empty()) {
      t = que.front();
      que.pop();

    }
   }

 private:
  void printTryy
};



#endif /* BINARY_TREE_H_ */
