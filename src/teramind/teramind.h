/*
 *      Author: andy
 */
#ifndef SRC_TERAMIND_TERAMIND_H_
#define SRC_TERAMIND_TERAMIND_H_

#include "terramind_1.h"
#include "terramind_2.h"
#include "terramind_3.h"
#include "terramind_4.h"
#include "terramind_5.h"
#include "terramind_6.h"
#include "terramind_7.h"
#include "terramind_8.h"
#include "terramind_9.h"
#include "terramind_10.h"
#include "terramind_11.h"
#include "terramind_12.h"

namespace terramind {

TEST_RESULT test() {
  __SCOPE_LOG__;
  assert(terramind_1::test());
  assert(terramind_2::test());
  assert(terramind_3::test());
  assert(terramind_4::test());
  assert(terramind_5::test());
  assert(terramind_6::test());
  assert(terramind_7::test());
  assert(terramind_8::test());
  assert(terramind_9::test());
  assert(terramind_10::test());
  assert(terramind_11::test());
  assert(terramind_12::test());

  RETURN_OK();
}

}  // namespace terramind

#endif /* SRC_TERAMIND_TERAMIND_H_ */
