#ifndef TEST_H_
#define TEST_H_

#if defined(__WIN32__) || defined (__WIN64__)
// windows code
#endif
#if defined(__linux__)
  //linux code goes here

  #pragma GCC diagnostic ignored "-Wunused-variable"
  #pragma GCC diagnostic ignored "-Wuninitialized"
  #pragma GCC diagnostic ignored "-Wunused-but-set-variable"
  #pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#endif

#include <stdio.h>
#include <iostream>
#include <assert.h>

#include "common/common.h"
#include "logger/logger.h"

#include "algoritms/algoritms.h"
#include "array/array.h"
#include "bits/bits.h"
#include "blockchain/blockchain.h"
#include "cast/cast.h"
#include "clock/clock.h"
#include "cpp1x/cpp1x.h"
#include "cpp17/test.h"
#include "cci4/cci4.h"
#include "cci5/cci5.h"
#include "cpp1x/cpp1x.h"
#include "cpp1x/quick_sort.h"
#include "diff/diff.h"
#include "epam/epam.h"
#include "epam/google.h"
#include "epam/google2.h"
#include "exception/exceptions.h"
#include "facebook/facebook.h"
#include "fast_io/fast_io.h"
#include "functors/functors.h"
#include "graph/graph.h"
#include "hash/hash.h"
#include "hrank/hrank.h"
#include "http/http.h"
#include "json/json.h"
#include "ipc/ipc.h"
#include "last/last_1.h"
#include "language/language.h"
#include "lambda/lambda.h"
#include "leap/leap.h"
#include "lge/test.h"
#include "lock-free/lock_free.h"
#include "memory/alignment.h"
#include "memory/memory.h"
#include "moto/moto.h"
#include "ms/ms.h"
#include "net/net.h"
#include "opencv/test.h"
#include "overloading/overloading.h"
#include "parser/parser.h"
#include "patterns/patterns.h"
#include "quiz/quiz.h"
#include "smart_ptr/smart_ptr.h"
#include "serialization/serialization.h"
#include "sqrt/sqrt.h"
#include "spb/spb.h"
#include "sqllite/sqllite.h"
#include "stackoverflow/stackoverflow.h"
#include "static/static.h"
#include "stl/stl.h"
#include "templates/templates.h"
#include "teramind/teramind.h"
#include "test_examples/test_examples.h"
#include "thread/threads.h"
#include "virtual/virtuals.h"
#include "yandex/yandex.h"

#endif /* TEST_H_ */
