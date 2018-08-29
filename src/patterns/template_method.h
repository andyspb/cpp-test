#ifndef _TEMPLATE_METHOD_H_
#define _TEMPLATE_METHOD_H_

#include <iostream>
namespace template_method {

class TemplateMethod {
 public:
  virtual ~TemplateMethod() {
  }
  void output() {
    write_string("TemplateMethod::output() Hello world!");
    write_endl();
  }
  ;
  virtual void write_string(const std::string &) = 0;
  virtual void write_endl() = 0;
};

class TemplateMethodImpl : public TemplateMethod {
 public:
  void write_string(const std::string & str) {
    std::cout << str;
  }
  void write_endl() {
    std::cout << std::endl;
  }
};

void test_template_method(TemplateMethod & hw) {
  hw.output();
}

int test() {
  printf("Template method\n");
  TemplateMethodImpl hw;
  test_template_method(hw);
  printf("\n");
  return 1;
}

}  // namespace template_method

#endif // _TEMPLATE_METHOD_H_
