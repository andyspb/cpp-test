/*
 * exceptions.h
 *
 *  Created on: Feb 28, 2014
 *      Author: andy
 */

#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <assert.h>
#include <iostream>
#include "exception.h"

namespace exceptions {

int test() {
  std::cout << "exceptions tests start:\n";
  assert(exception_::test());
  std::cout << "exceptions tests end:\n";
  return 0;
}

}  // namespace exceptions


#endif /* EXCEPTIONS_H_ */
