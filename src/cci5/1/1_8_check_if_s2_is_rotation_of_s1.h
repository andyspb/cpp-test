/*
 * 1_8_check_if_s2_is_rotation_of_31.h
 *
 *  Created on: 26 дек. 2014 г.
 *      Author: andy
 */

#ifndef CHECK_IF_S2_IS_ROTATION_OF_S1_H_
#define CHECK_IF_S2_IS_ROTATION_OF_S1_H_

#include <string>

namespace check_is_rotation {

bool isRotation(std::string s1, std::string s2) {
  size_t len = s1.length();
  /* check that si and s2 are equal length and not empty */
  if (len == s2.length() && len > 0) {
    /* concatenate s1 and s1 within new buffer */

    std::string s1s1 = s1 + s1;
    return s1.find(s2) != std::string::npos;
  }
  return false;
}

int test() {
  return 1;
}

}
  // namespace check_is_rotation

#endif /* CHECK_IF_S2_IS_ROTATION_OF_S1_H_ */
