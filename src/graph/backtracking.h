/*
 * backtracking.h
 *
 *  Created on: 10 ���. 2015 �.
 *      Author: andy
 */

#ifndef BACKTRACKING_H_
#define BACKTRACKING_H_

namespace backtracking {
// pseudo

struct Node {
  Node* next;
  int value;
};

//#if defined(__GNUC__) and !defined(__WIN64__)
///*
//bool solve(Node* n, int goal) {
//  if (!n->next) {
//    if (n->next->value == goal)  //the leaf is a goal node,
//      return true;
//    else
//      return false;
//  } else {
//    for (auto c : n) {
//      if (solve(c)) {
//        return true;
//      }
//    }
//    return false;
//  }
//}
//*/
//#endif

//TEST_RESULT test() {
//  __SCOPE_LOG__;
//  RETURN_OK();
//}

}  // namespace backtracking

#endif /* BACKTRACKING_H_ */
