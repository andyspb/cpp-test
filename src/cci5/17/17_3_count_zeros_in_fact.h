/*
 * 17_3_count_zeros_in_fact.h
 *
 *  Created on: 06 џэт. 2015 у.
 *      Author: andy
 */

#ifndef _COUNT_ZEROS_IN_FACT_H_
#define _COUNT_ZEROS_IN_FACT_H_

int factorsOf5(int i) {
  int count = 0;
  while (i % 5 == 0) {
    count++;
    i /= 5;
  }
  return count;
}

int countFactZeros(int num) {
  int count = 0;
  if (num < 0) {
    return -1;
  }
  for (int i = 5; num / i > 0; i *= 5) {
    count += num / i;
  }
  return count;
}

#endif /* 17_3_COUNT_ZEROS_IN_FACT_H_ */
