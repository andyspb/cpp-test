#ifndef _TEMPLATES_H_
#define _TEMPLATES_H_

#include <iostream>

#include <assert.h>
#include "template_factorial.h"
#include "template_keyword.h"
#include "template_method_in_non_template_class.h"
#include "template_mycontainer.h"
#include "template_test1.h"
#include "template_test2.h"
#include "template_test3.h"
#include "template_test4.h"
#include "template_test5.h"

namespace templates {
int test() {
   std::cout << "Templates tests start:\n";
//    assert(template_factorial::test());
//    assert(template_keyword::test());
//    assert(template_method_in_non_template_class::test());
//    assert(template_mycontainer::test());
//    assert(template_test1::test());
//    assert(template_test2::test());
//    assert(template_test3::test());
//    assert(template_test4::test());
  assert(template_test5::test());
   std::cout << "Templates tests end\n";
  return 1;
}
}  // namespace templates

#endif // _TEMPLATES_H_
