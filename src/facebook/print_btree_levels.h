/*
 * print_btree_levels.h
 *
 *  Created on: 21 дек. 2013 г.
 *      Author: andy
 */

/*
 print binary tree level by level

 A
 B        C
 D   E         F
 Y

 A
 BC
 DEF
 */

#ifndef PRINT_BTREE_LEVELS_H_
#define PRINT_BTREE_LEVELS_H_

namespace print_btree_levels {
struct BNode {
  BNode(char c)
      : data(c),
        left(0),
        right(0) {
  }
  ;
  char data;
  BNode *left;
  BNode *right;
};

void swap(std::queue<BNode*>& q1, std::queue<BNode*>& q2) {
  std::queue<BNode*> temp1;
  std::queue<BNode*> temp2;
  while (!q1.empty()) {
    BNode * node = q1.front();
    temp1.push(node);
    q1.pop();
  }
  while (!q2.empty()) {
    BNode * node = q2.front();
    temp2.push(node);
    q2.pop();
  }
  while (!temp1.empty()) {
    BNode * node = temp1.front();
    q2.push(node);
    temp1.pop();
  }
  while (!temp2.empty()) {
    BNode * node = temp2.front();
    q1.push(node);
    temp2.pop();
  }

}

void print_btree(BNode* root) {
  if (!root) {
    return;
  }

  std::queue<BNode*> currentLevel, nextLevel;
  currentLevel.push(root);
  while (!currentLevel.empty()) {
    BNode * currNode = currentLevel.front();
    currentLevel.pop();
    if (currNode) {
      std::cout << currNode->data << " ";
      nextLevel.push(currNode->left);
      nextLevel.push(currNode->right);
    }
    if (currentLevel.empty()) {
      std::cout << std::endl;
      swap(currentLevel, nextLevel);
    }
  }
}

void printLevelOrder(BNode *root) {
  if (!root)
    return;
  int nodesInCurrentLevel(1), nodesInNextLevel(0);
  std::queue<BNode*> queue;
  queue.push(root);
  while (!queue.empty()) {
    BNode *currNode = queue.front();
    queue.pop();
    --nodesInCurrentLevel;
    if (currNode) {
      std::cout << currNode->data << " ";
      queue.push(currNode->left);
      queue.push(currNode->right);
      nodesInNextLevel += 2;
    }
    if (nodesInCurrentLevel == 0) {
      std::cout << std::endl;
      nodesInCurrentLevel = nodesInNextLevel;
      nodesInNextLevel = 0;
    }
  }

}

int test() {
  std::cout << "Test print_btree_levels: --->\n";
  BNode a('A');
  BNode b('B');
  BNode c('C');
  a.left = &b;
  a.right = &c;
  BNode d('D');
  BNode e('E');
  b.left = &d;
  b.right = &e;
  BNode f('F');
  c.left = &f;

  std::cout << "print_btree()\n";
  print_btree(&a);

  std::cout << "printLevelOrder()\n";
  printLevelOrder(&a);
  std::cout << "<--- end test\n";
  return 1;
}

}  // namespace print_btree_levels

#endif /* PRINT_BTREE_LEVELS_H_ */
