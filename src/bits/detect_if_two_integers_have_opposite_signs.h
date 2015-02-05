/*
 * detect_if_two_integers_have_opposite_signs.h
 *
 *  Created on: 01 ����. 2015 �.
 *      Author: andy
 */

#ifndef DETECT_IF_TWO_INTEGERS_HAVE_OPPOSITE_SIGNS_H_
#define DETECT_IF_TWO_INTEGERS_HAVE_OPPOSITE_SIGNS_H_

#include <limits.h>

namespace detect_if_two_integers_have_opposite_signs {

bool oppositeSigns(int x, int y) {
  return ((x ^ y) >> ((sizeof(int)*CHAR_BIT)-1));
}

int test() {
  return 1;
}

}  // namespace  detect_if_two_integers_have_opposite_signs

#endif /* DETECT_IF_TWO_INTEGERS_HAVE_OPPOSITE_SIGNS_H_ */
