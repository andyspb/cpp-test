/*
 * bits_field.h
 *
 *  Created on: Sep 14, 2015
 *      Author: andy
 */

#ifndef SRC_BITS_BITS_FIELD_H_
#define SRC_BITS_BITS_FIELD_H_

#include <iostream>

namespace bits_field {

struct S1 {
  unsigned int a;
  unsigned int b;
  unsigned int C;
  unsigned int D;
};

struct S2 {
  unsigned int a: 10;
  unsigned int b: 10;
  unsigned int c: 10;
  unsigned int d: 3;
};

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;
  std::cout << "sizeof(S1)=" << sizeof(S1) << std::endl;
  std::cout << "sizeof(S2)=" << sizeof(S2) << std::endl;
  RETURN_OK();
}

}  // namespace bits_field



#endif /* SRC_BITS_BITS_FIELD_H_ */
