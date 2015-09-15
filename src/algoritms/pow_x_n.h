/*
 * pow_x_n.h
 *
 *  Created on: 29 ���� 2015 �.
 *      Author: andy
 */

#ifndef SRC_ALGORITMS_POW_X_N_H_
#define SRC_ALGORITMS_POW_X_N_H_

namespace pow_x_n {

int power(int x, unsigned int y) {
  if (y == 0) {
    return 1;
  } else if (y % 2 == 0) {
    return power(x, y / 2) * power(x, y / 2);
  } else {
    return x * power(x, y / 2) * power(x, y / 2);
  }
}

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;
  int x = 2;
  unsigned int y = 3;
  LOG(INFO) << x << "^" << y << "= " << power(x, y);
  RETURN_OK();
}

}  // namespace pow_x_n

#endif /* SRC_ALGORITMS_POW_X_N_H_ */
