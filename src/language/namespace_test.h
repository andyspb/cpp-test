#ifndef NAMESPACE_TEST_H_
#define NAMESPACE_TEST_H_

#include <iostream>

namespace namespace_test {

namespace outer {
 int ii = 10;

 namespace {
   int i = 20;
 }
}

int test() {
	std::cout << "Test inner unnamed namespace: " << std::endl;
	std::cout << "i = " << outer::i << std::endl;
  return 1;
}

}

#endif  // NAMESPACE_TEST_H_
