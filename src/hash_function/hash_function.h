//  hashcodes.h
//  author: andrey.krutogolov@gmail.com
//  date:   Dec 10, 2012

#ifndef HASHCODES_H_
#define HASHCODES_H_

#include <cassert>

#include "../hash_function/hash_function_for_string.h"
#include "../hash_function/hash_function_sample.h"
#include "../hash_function/hashtable.h"
#include "../hash_function/perfect_hash_function.h"

namespace hash_function{

TEST_RESULT test() {
  __SCOPE_LOG__;
  //assert(hash_function_test::test());
  //assert(hash_table::test());
//  assert(perfect_hash_function::test());
  assert(hash_function_for_string::test());
  RETURN_OK();
}

}  // hashcodes

#endif  // HASHCODES_H_