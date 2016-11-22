//  hashcodes.h
//  author: andrey.krutogolov@gmail.com
//  date:   Dec 10, 2012

#ifndef HASHCODES_H_
#define HASHCODES_H_

#include <assert.h>

#include "../hash/hash_function_sample.h"
#include "../hash/hashtable.h"
#include "../hash/perfect_hash_function.h"
#include "../hash/string_hash_function.h"

namespace hash {

TEST_RESULT test() {
  __SCOPE_LOG__;
  //assert(hash_function_test::test());
  //assert(hash_table::test());
  assert(perfect_hash_function::test());

  RETURN_OK();
}

}  // hashcodes

#endif  // HASHCODES_H_
