#ifndef TEMPLATE_METHOD_IN_NON_TEMPLATE_CLASS_H_
#define TEMPLATE_METHOD_IN_NON_TEMPLATE_CLASS_H_

#include <iostream>
#include <string>

namespace template_method_in_non_template_class {
class InnertemplateTest {
  public:
    InnertemplateTest()
        : ptr_(0) {
    }
    virtual ~InnertemplateTest(void) {
    }

    template<class T>
    void foo_templ(const T&);

  private:
    void* ptr_;
};

template<class T>  //SOMETHING WRONG WITH THIS DEFINITION
void InnertemplateTest::foo_templ(const T& obj) {
  LOG(INFO) << "From foo_templ()";
}

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;
  InnertemplateTest stack;
  stack.foo_templ<int>(5);

  RETURN_OK();
}
}  // namespace template_method_in_non_template_class

#endif /* TEMPLATE_METHOD_IN_NON_TEMPLATE_CLASS_H_ */
