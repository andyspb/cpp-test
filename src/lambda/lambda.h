//  lambda.h
//  author: andrey.krutogolov@gmail.com
//  date:   22.02.2013

#ifndef LAMBDA_H_
#define LAMBDA_H_

#include <assert.h>

#include "lambda_test.h"
#include "lambda_test1.h"
#include "lambda_test2.h"
#include "lambda_test3.h"

namespace lambda {

TEST_RESULT test() {
  __SCOPE_LOG__;
  assert(lambda_test::test());
//  assert(lambda_test1::test());
//  assert(lambda_test2::test());
//  assert(lambda_test3::test());
  RETURN_OK();
}

}

#endif  // LAMBDA_H_
