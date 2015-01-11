/*
 * backtracking.h
 *
 *  Created on: 10 џэт. 2015 у.
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
        for each child c of n {
            if solve(c) succeeds, return true
        }
        return false
    }
}
}



#endif /* BACKTRACKING_H_ */
