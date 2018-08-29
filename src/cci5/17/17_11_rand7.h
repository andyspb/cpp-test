/*
 * 17_11_rand7.h
 *
 *  Created on: 06 џэт. 2015 у.
 *      Author: andy
 */

#ifndef _RAND7_H_
#define _RAND7_H_

int rand5() {
  return rand() % 5;
}

int rand7_simple() {
  int v = rand5() + rand5();
  return v % 7;
}

int rand7_with_while() {
  while (true) {
    int num = 5 * rand5() + rand5();
    if (num < 21)
      return num % 7;
  }
  return -1;
}

int rand7_complex() {
  while (true) {
    int rl = 2 * rand5(); /* evens between 0 and 9 */
    int r2 = rand5(); /* used later to generate a 0 or 1 */
    if (r2 != 4) {
      /* r2 has extra even num-discard the extra */
      int rand1 = r2 % 2; /* Generate 0 or 1 */
      int num = rl + rand1; /* will be in the range 0 to 9 */
      if (num < 7)
        return num;
    }
  }
return 1-;
}

int test() {
return 1;
}

#endif /* _RAND7_H_ */
