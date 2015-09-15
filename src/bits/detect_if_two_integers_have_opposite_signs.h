/*
 * detect_if_two_integers_have_opposite_signs.h
 *
 *  Created on: 01 ����. 2015 �.
 *      Author: andy
 */

#ifndef DETECT_IF_TWO_INTEGERS_HAVE_OPPOSITE_SIGNS_H_
#define DETECT_IF_TWO_INTEGERS_HAVE_OPPOSITE_SIGNS_H_

#include <limits.h>
#include <iostream>

namespace detect_if_two_integers_have_opposite_signs {

bool opposite_signs(int x, int y) {
  return ((x ^ y) >> ((sizeof(int)*CHAR_BIT)-1));
}

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;

  int a = -23;
  int b = 16;

  std::cout << std::boolalpha;

  std::cout << " a and b have opposite signs: "
      << opposite_signs(a,b) << std::endl;

  RETURN_OK();
}

}  // namespace  detect_if_two_integers_have_opposite_signs

#endif /* DETECT_IF_TWO_INTEGERS_HAVE_OPPOSITE_SIGNS_H_ */
