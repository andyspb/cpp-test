#include "test.h"

#include <stdio.h>
#include <iostream>
#include <assert.h>

#include "common/binary_tree.h"
#include "common/circular_que.h"
#include "common/constants.h"
#include "common/linked_list.h"
#include "common/node.h"

#include "logger/log_template.h"
#include "logger/logger.h"

#include "algoritms/algoritms.h"
#include "array/array.h"
#include "bits/bits.h"
#include "clock/clock.h"
#include "cpp0x/cpp0x.h"
#include "cpp11/cpp11.h"
#include "cci4/cci4.h"
#include "cci5/cci5.h"
#include "exception/exceptions.h"
#include "facebook/facebook.h"
#include "func/func.h"
#include "hashcode/hashcodes.h"
#include "language/language.h"
#include "lambda/lambda.h"
#include "lock-free/lock_free.h"
#include "memory/mem_test.h"
#include "patterns/patterns.h"
#include "templates/templates.h"

#include "smart_ptr/smart_ptr.h"
#include "spb/spb.h"
#include "sqrt/sqrt.h"
#include "static/static.h"
#include "stl/stl.h"
#include "thread/tests.h"
#include "tests/tests.h"
#include "quiz/quiz.h"
#include "virtual/virtuals.h"


#include "overloading/overloading.h"
#include "moto/moto.h"

#include "last/last_1.h"
#include "epam/epam.h"
#include "epam/google.h"
#include "epam/google2.h"

#include "ms/ms.h"
#include "memory/alignment.h"

#include "cpp11/quick_sort.h"


int main(int argc, char **argv) {
//  logger::Log().Get(LogLevel::INFO) << __PRETTY_FUNCTION__;
  LOG(INFO) << __PRETTY_FUNCTION__;

//  assert(cpp11::test());
// assert(algorithms::test());
//   assert(binary_tree::test());
//  assert(bits::test());
//  assert(cpp0x::test());
//  assert(cci4::test());
//  assert(cci5::test());
//  assert(exceptions::test());
//  assert(facebook::test());
//  assert(func::test());
//  assert(hashcodes::test());
//  assert(lambda::test());
  assert(language::test());

//  assert(sqrt_::test());
//  assert(mem_test::test());
//assert(moto::test());
//    assert(templates::test());
//  assert(spb::test());
//  assert(hashmap::test());
//  assert(overloading::test());

  //  assert(patterns::test());
//  assert(quiz::test());
//  assert(smart_ptr::test());
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

  return 0;
}

