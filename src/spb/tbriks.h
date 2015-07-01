/*
 * tbriks.h
 *
 *  Created on: 26 θώνÿ 2015 γ.
 *      Author: andy
 */

#ifndef SRC_SPB_TBRIKS_H_
#define SRC_SPB_TBRIKS_H_

namespace tbriks {

int test() {
  LOG(INFO) << __PRETTY_FUNCTION__;
  int value = 0xABCDEE00u;
  unsigned char* pc = (unsigned char*) &value;
//  for (;pc<(char*)(&value)+4; pc++) {
  printf("%2x\n", *pc);
//  }

  return 1;
}

}  // namespace tbriks

#endif /* SRC_SPB_TBRIKS_H_ */
