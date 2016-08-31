/*
 * fibbonachi_sum.h
 *
 *  Created on: Apr 26, 2016
 *      Author: andy
 */

#ifndef SRC_ALGORITMS_FIBBONACHI_SUM_H_
#define SRC_ALGORITMS_FIBBONACHI_SUM_H_

namespace fibbonachi_sum {

void print_fibboonachi_sum(int n) {
  if (n < 0)
    return;
  int count, t1 = 0, t2 = 1, display = 0;
  if (n >= 0)
    printf("%d ", t1);
  if (n >= 1)
    printf("%d ", t2);
  count = 2; /* count=2 because first two terms are already displayed. */
  while (t1 < n) {
    display = t1 + t2;
    t1 = t2;
    t2 = display;
    ++count;
    printf("%d ", display);
  }
  printf("\n");
}

TEST_RESULT test() {
  __SCOPE_LOG__;
  print_fibboonachi_sum(4);
  RETURN_OK();
}

}  // namespace fibbonachi_sum

#endif /* SRC_ALGORITMS_FIBBONACHI_SUM_H_ */
