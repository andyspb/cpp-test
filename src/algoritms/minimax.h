/*
 * minimax.h
 *
 *  Created on: Jul 26, 2016
 *      Author: andy
 */

#ifndef SRC_ALGORITMS_MINIMAX_H_
#define SRC_ALGORITMS_MINIMAX_H_

// C++ program to demonstrate working of Alpha-Beta Pruning
namespace minimax {

//Initial values of Aplha and Beta
const int MAX = 1000;
const int MIN = -1000;

// Returns optimal value for current player (Initially called
// for root and maximizer)
int minimax(int depth, int nodeIndex, bool maximizingPlayer, int values[],
            int alpha, int beta) {
  // Terminating condition. i.e leaf node is reached
  if (depth == 3)
    return values[nodeIndex];

  if (maximizingPlayer) {
    int best = MIN;

    // Recur for left and right children
    for (int i = 0; i < 2; i++) {
      int val = minimax(depth + 1, nodeIndex * 2 + i, false, values, alpha,
                        beta);
      best = std::max(best, val);
      alpha = std::max(alpha, best);

      // Alpha Beta Pruning
      if (beta <= alpha)
        break;
    }
    return best;
  } else {
    int best = MAX;

    // Recur for left and right children
    for (int i = 0; i < 2; i++) {
      int val = minimax(depth + 1, nodeIndex * 2 + i, true, values, alpha,
                        beta);
      best = std::min(best, val);
      beta = std::min(beta, best);

      // Alpha Beta Pruning
      if (beta <= alpha)
        break;
    }
    return best;
  }
}

TEST_RESULT test() {
  __SCOPE_LOG__;
  int values[8] = { 3, 5, 6, 9, 1, 2, 0, -1 };
  LOG(INFO) << "The optimal value is : "
      << minimax(0, 0, true, values, MIN, MAX);
  RETURN_OK();
}

}

#endif /* SRC_ALGORITMS_MINIMAX_H_ */
