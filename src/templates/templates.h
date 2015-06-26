#ifndef _TEMPLATES_H_
#define _TEMPLATES_H_

#include <iostream>

#include <assert.h>
#include "template_factorial.h"
#include "template_fibonacci.h"
#include "template_keyword.h"
#include "template_method_in_non_template_class.h"
#include "template_mycontainer.h"
#include "template_test1.h"
#include "template_test2.h"
#include "template_test3.h"
#include "template_test4.h"
#include "template_test5.h"

#include "../logger/logger.h"

namespace templates {

template<class T> void f() {
}
;
template<int i> void f() {
}
;

template<class T, int size>
class Myfilebuf {
  T* filepos;
  static int array[size];
 public:
  Myfilebuf(): filepos(0) { /* ... */};
  ~Myfilebuf() {};
  int advance() {return 1;};
  // function defined elsewhere in program
};

int template_test() {
  f<int()>();
  return 1;
}

int test() {
  logger::Log().Get(INFO) << "Templates tests";

  template_test();

  //    assert(template_factorial::test());
  assert(template_fibonacci::test());
//    assert(template_keyword::test());
//    assert(template_method_in_non_template_class::test());
//    assert(template_mycontainer::test());
//    assert(template_test1::test());
//    assert(template_test2::test());
//    assert(template_test3::test());
//    assert(template_test4::test());
//  assert(template_test5::test());
  return 1;
}
}  // namespace templates

#endif // _TEMPLATES_H_
