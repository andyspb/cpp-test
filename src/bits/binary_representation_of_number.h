/*
 * binary_representation_of_number.h
 *
 *  Created on: 01 ����. 2015 �.
 *      Author: andy
 */

#ifndef BINARY_REPRESENTATION_OF_NUMBER_H_
#define BINARY_REPRESENTATION_OF_NUMBER_H_

namespace binary_representation_of_number {

void bin_iter(unsigned n) {
  unsigned i;
  for (i = 1 << 31; i > 0; i = i / 2)
    (n & i) ? printf("1") : printf("0");
}

void bin_rec(unsigned n) {
  /* step 1 */
  if (n > 1)
    bin_rec(n / 2);

  /* step 2 */
  printf("%d", n % 2);
}

TEST_RESULT test() {
  __SCOPE_LOG__;
  bin_iter(7);
  printf("\n");
  bin_iter(4);
  RETURN_OK();
}
}  // binary_representation_of_number

#endif /* BINARY_REPRESENTATION_OF_NUMBER_H_ */
