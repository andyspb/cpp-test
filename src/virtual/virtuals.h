#ifndef VIRTUALS_H_
#define VIRTUALS_H_

#include <assert.h>
#include "virt_access.h"
#include "virt_cast_1.h"
#include "virt_cast_2.h"
#include "virt_func_1.h"
#include "virt_func_2.h"
#include "virt_func_3.h"
#include "virt_func_4.h"
#include "virt_func_5.h"
#include "virt_func_6.h"
#include "virt_inheritance.h"
#include "virt_private_access.h"

namespace virtuals {

int test() {
//  assert(virt_cast_1::test());
//  assert(virt_cast_2::test());
//  assert(virt_func_1::test());
//  assert(virt_func_2::test());
//  assert(virt_func_3::test());
//  assert(virt_func_4::test());
//  assert(virt_inheritance::test());
//  assert(virt_private_access::test());
//  assert(virt_func_5::test());
  assert(virt_func_6::test());
  return 1;
}
} // namespace virtuals

#endif /* VIRTUALS_H_ */
