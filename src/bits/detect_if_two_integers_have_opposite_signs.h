/*
 * detect_if_two_integers_have_opposite_signs.h
 *
 *  Created on: 01 февр. 2015 г.
 *      Author: andy
 */

#ifndef DETECT_IF_TWO_INTEGERS_HAVE_OPPOSITE_SIGNS_H_
#define DETECT_IF_TWO_INTEGERS_HAVE_OPPOSITE_SIGNS_H_

#include <limits.h>

namespace detect_if_two_integers_have_opposite_signs {

bool oppositeSigns(int x, int y) {
  return ((x ^ y) >> ((sizeof(int)*CHAR_BIT)-1));
}

}  // namespace  detect_if_two_integers_have_opposite_signs

#endif /* DETECT_IF_TWO_INTEGERS_HAVE_OPPOSITE_SIGNS_H_ */
