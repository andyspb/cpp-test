//  test.h
//  author: andrey.krutogolov@gmail.com
//  date:   13.03.2013

#ifndef TESTS_H_
#define TESTS_H_

#include "tests1.h"
#include "tests2.h"
#include "tests3.h"
#include "tests4.h"
#include "tests5.h"
#include "tests6.h"
#include "tests7.h"
#include "tests8.h"
#include "tests9.h"
#include "tests10.h"
#include "tests11.h"
#include "tests12.h"
#include "tests13.h"
#include "tests14.h"
#include "tests15.h"
#include "tests16.h"
#include "tests17.h"
#include "tests18.h"
#include "tests19.h"
#include "tests20.h"
#include "tests21.h"
#include "tests22.h"

#include <assert.h>

namespace tests {

int test() {
  assert(tests1::test());
  assert(tests2::test());
  assert(tests3::test());
  assert(tests4::test());
  tests5::main();
  tests6::main();
  tests7::main();
  tests8::main();
  tests9::main();
    tests10::main();
  tests11::main();
    tests12::main();
  tests13::main();
  tests14::main();
  tests15::main();
  tests16::main();
  tests17::main();
  tests18::main();
  tests19::main();
  tests20::main();
  tests21::main();
  tests22::main();
  return 1;
}

}  // namespace tests

#endif  // TEST_H_
