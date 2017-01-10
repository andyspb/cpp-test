#ifndef VIRTUALS_H_
#define VIRTUALS_H_

#include <assert.h>
#include "pure_virtual.h"
#include "overrides.h"
#include "virt_access.h"
#include "virt_cast_1.h"
#include "virt_cast_2.h"
#include "virt_func_1.h"
#include "virt_func_2.h"
#include "virt_func_3.h"
#include "virt_func_4.h"
#include "virt_func_5.h"
#include "virt_func_6.h"
#include "virt_func_7.h"
#include "virt_func_8.h"
#include "virt_func_9.h"
#include "virt_inheritance.h"
#include "virt_private_access.h"

namespace virtuals {

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;
  assert(overrides::test());
//  assert(virt_cast_1::test());
//  assert(virt_cast_2::test());
//  assert(virt_func_1::test());
//  assert(virt_func_2::test());
//  assert(virt_func_3::test());
//  assert(virt_func_4::test());
//  assert(virt_inheritance::test());
//  assert(virt_private_access::test());
//  assert(virt_func_5::test());
//  assert(virt_func_6::test());
//  assert(virt_func_7::test());
//  assert(virt_func_8::test());
//  assert(virt_func_9::test());
//  assert(pure_virtual::test());
  RETURN_OK();
}
}  // namespace virtuals

#endif /* VIRTUALS_H_ */
