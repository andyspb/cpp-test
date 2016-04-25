//  test.h
//  author: andrey.krutogolov@gmail.com
//  date:   13.03.2013

#ifndef TESTS_H_
#define TESTS_H_

#include <assert.h>

#include "test_1.h"
#include "test_10.h"
#include "test_11.h"
#include "test_12.h"
#include "test_13.h"
#include "test_14.h"
#include "test_15.h"
#include "test_16.h"
#include "test_17.h"
#include "test_18.h"
#include "test_19.h"
#include "test_2.h"
#include "test_20.h"
#include "test_21.h"
#include "test_22.h"
#include "test_23.h"
#include "test_24.h"
#include "test_25.h"
#include "test_3.h"
#include "test_4.h"
#include "test_5.h"
#include "test_6.h"
#include "test_7.h"
#include "test_8.h"
#include "test_9.h"

namespace tests {

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;
//  assert(test_1::test());
//  assert(test_2::test());
//  assert(test_3::test());
//  assert(test_4::test());
//  assert(test_5::test());
//  assert(test_6::test());
//  assert(test_7::test());
//  assert(test_8::test());
//  assert(test_9::test());
//  assert(test_10::test());
//  assert(test_11::test());
//  assert(test_12::test());
//  assert(test_13::test());
//  assert(test_14::test());
//  assert(test_15::test());
//  assert(test_16::main());
//  assert(test_17::main());
//  assert(test_18::test());
//  assert(test_19::test());
//  assert(test_20::test());
//  assert(test_21::test());
//  assert(test_22::test());
//  assert(test_23::test());
//  assert(test_24::test());
  assert(test_25::test());
  RETURN_OK();
}

}  // namespace tests

#endif  // TEST_H_
