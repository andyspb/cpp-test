#ifndef TEST_H_
#define TEST_H_

#ifdef __linux__
  //linux code goes here
  #pragma GCC diagnostic ignored "-Wunused-variable"
  #pragma GCC diagnostic ignored "-Wuninitialized"
  #pragma GCC diagnostic ignored "-Wunused-but-set-variable"
  #pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#elif _WIN32
  // windows code goes here
#else
  // something else
#endif

#include <stdio.h>
#include <assert.h>
#include "algoritms/algoritms.h"
#include "array/array.h"
#include "clock/clock.h"
#include "cpp0x/cpp0x.h"
#include "cracking_code_interview/cracking.h"
#include "exception/exceptions.h"
#include "facebook/facebook.h"
#include "func/func.h"
#include "hashcode/hashcodes.h"
#include "language/language.h"
#include "lambda/lambda.h"
#include "lock-free/lock_free.h"
#include "patterns/patterns.h"
#include "templates/templates.h"
#include "smart_ptr/smart_ptr.h"
#include "static/static.h"
#include "tests/tests.h"
#include "quiz/quiz.h"
#include "virtual/virtuals.h"

#include "last/last_1.h"

#endif /* TEST_H_ */
