/*
 * stackoverflow.h
 *
 *  Created on: Jul 21, 2015
 *      Author: andy
 */

#ifndef SRC_STACKOVERFLOW_STACKOVERFLOW_H_
#define SRC_STACKOVERFLOW_STACKOVERFLOW_H_

#include "so_1.h"

namespace stackoverflow {

int test() {
  LOG(INFO) << __PRETTY_FUNCTION__;

  assert(so_1::test());

  return 1;
}

}

#endif /* SRC_STACKOVERFLOW_STACKOVERFLOW_H_ */
