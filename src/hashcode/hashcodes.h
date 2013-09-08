//  hashcodes.h
//  author: andrey.krutogolov@gmail.com
//  date:   Dec 10, 2012

#ifndef HASHCODES_H_
#define HASHCODES_H_

#include <assert.h>
#include "hash_function_sample.h"

namespace hashcodes {

int test() {
  assert(hash_function_test::test());
  return 1;
}

}  // hashcodes

#endif  // HASHCODES_H_
