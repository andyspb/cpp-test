#ifndef _PREFIX_POSTFIX_TEST_H_
#define _PREFIX_POSTFIX_TEST_H_

#include <iostream>

namespace prefix_postfix_test {
int test() {
  int i = 0;
  std::cout << "i=" << i << std::endl;

  //i = (i++) + (++i);
  //i = (++i);
  //i = (((i++)++)++);

  std::cout << "i=" << i << std::endl;
  return 1;
}
} // namespace prefix_postfix_test

#endif // _PREFIX_POSTFIX_TEST_H_
