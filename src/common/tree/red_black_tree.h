/*
 * red_black_tree.h
 *
 *  Created on: 15 џэт. 2015 у.
 *      Author: andy
 */

#ifndef RED_BLACK_TREE_H_
#define RED_BLACK_TREE_H_

//typedef int T; /* type of item to be stored */
#define compLT(a,b) (a < b)
#define compEQ(a,b) (a == b)

typedef enum {
  BLACK,
  RED
} nodeColor;

template<typename T>
struct RedBlackNode {
  RedBlackNode *left; /* left child */
  RedBlackNode *right; /* right child */
  RedBlackNode *parent; /* parent */
  nodeColor color; /* node color (BLACK, RED) */
  T data; /* data stored in node */
};

#endif /* RED_BLACK_TREE_H_ */
