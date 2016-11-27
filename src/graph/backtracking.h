/*
 * backtracking.h
 *
 *  Created on: 10 ���. 2015 �.
 *      Author: andy
 */

#ifndef BACKTRACKING_H_
#define BACKTRACKING_H_

#include "../common/node.h"

namespace backtracking {

// pseudo
bool solve(Node* n) {
  if (!n->next) {
  if the leaf is a goal node, return true
  else return false
} else {
  for (auto c : n) {
    if (solve(c)) {
      return true;
    }
  }
return false
}
}
}

#endif /* BACKTRACKING_H_ */
