#include "test.h"

#include <stdio.h>
#include <iostream>
#include <assert.h>

#include "common/common.h"

#include "logger/logger.h"

#include "algoritms/algoritms.h"
#include "array/array.h"
#include "bits/bits.h"
#include "clock/clock.h"
#include "cpp1x/cpp1x.h"
#include "cci4/cci4.h"
#include "cci5/cci5.h"
#include "cpp1x/cpp1x.h"
#include "cpp1x/cpp1x_quick_sort.h"
#include "exception/exceptions.h"
#include "facebook/facebook.h"
#include "func/func.h"
#include "hashtable/hashtable.h"
#include "hashcode/hashcodes.h"
#include "language/language.h"
#include "lambda/lambda.h"
#include "lock-free/lock_free.h"
#include "memory/memory.h"
#include "patterns/patterns.h"
#include "templates/templates.h"
#include "teramind/teramind.h"

#include "smart_ptr/smart_ptr.h"
#include "spb/spb.h"
#include "sqrt/sqrt.h"
#include "static/static.h"
#include "stackoverflow/stackoverflow.h"
#include "stl/stl.h"
#include "thread/threads.h"
#include "tests/tests.h"
#include "quiz/quiz.h"
#include "virtual/virtuals.h"


#include "overloading/overloading.h"
#include "moto/moto.h"

#include "last/last_1.h"
#include "epam/epam.h"
#include "epam/google.h"
#include "epam/google2.h"
#include "http/server.h"
#include "diff/diff.h"

#include "ms/ms.h"
#include "memory/alignment.h"

#include "sqllite/sqllite.h"

int main(int argc, char **argv) {
  LOG(INFO) << __PRETTY_FUNCTION__;

  assert(sqllite::test());
//  assert(threads::test());

//  assert(diff::test());
//  assert(http_server::test());
//  assert(algorithms::test());
//  assert(binary_tree::test());
//  assert(bits::test());
//  assert(cpp1x::test());
//  assert(cci4::test());
//  assert(cci5::test());
//  assert(exceptions::test());
//  assert(facebook::test());
//  assert(func::test());
//  assert(hashcodes::test());
//  assert(lambda::test());
//  assert(language::test());

//  assert(sqrt_::test());
//  assert(mem_test::test());
//assert(moto::test());
//  assert(templates::test());
//  assert(teramind::test());
//  assert(spb::test());
//  assert(hashmap::test());
//  assert(overloading::test());

  //  assert(patterns::test());
//  assert(quiz::test());
//  assert(smart_ptr::test());

//  assert(stackoverflow::test());

//  assert(stl::test());
//  assert(binary_tree::test());
//  assert(tests::test());
//  assert(virtuals::test());

//  assert(last_1::test());
//  assert(static_::test());

//  assert(array::test());
//  assert(clock_::test());

//  assert(quicksort_cpp11::test());

//  assert(threads::test());
//  assert(futures::test());

//  assert(epam::test() );
//  assert(ms::test() );
//    assert(google_2::test());
//  assert(alignment::test());

//  int arr[10];
//  int *pa = arr;

  LOG(INFO) << "<< return from " << __FUNCTION__;
  return 0;
}

