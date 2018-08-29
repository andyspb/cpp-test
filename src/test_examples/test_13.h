// tests13.h
// author: andrey.krutogolov@gmail.com
// date:   24.03.2013

#ifndef TESTS13_H_
#define TESTS13_H_

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <sstream>
#include <stdexcept>

namespace test_13 {
inline std::string stringify(int x) {
  std::ostringstream o;
  if (!(o << x))
    std::cout << "bad conversion" << std::endl;
  return o.str();
}

class A {
 public:
  A();
  A(std::string pstring) {
    name = pstring;
  }
  A(const A& pA) {
    name = pA.name + "copy";
    std::cout << "copy constructor of " << name << " is called" << std::endl;

  }
  ~A() {
    std::cout << "destructor of " << name << " is called" << std::endl;
  }

  std::string name;
};

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;

  int i = 0;
  std::vector<A> ACollection;
  std::string tempString;

  for (i = 0; i < 10; i++) {
    tempString = stringify(i);
    A tempA(tempString);
    ACollection.push_back(tempA);
    std::cout << "currently adding object " << tempString << std::endl;
  }
  std::cout << "size of the collection is " << ACollection.size() << std::endl;

  for (i = 0; i < 10; i++) {
    std::cout << ACollection[i].name << std::endl;
  }

  RETURN_OK();
}

}  // namespace tests13

#endif  // TESTS13_H_
