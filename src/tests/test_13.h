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

using namespace std;

namespace test_13 {
inline std::string stringify(int x) {
  std::ostringstream o;
  if (!(o << x))
    cout << "bad conversion" << endl;
  return o.str();
}

class A {
 public:
  A();
  A(string pstring) {
    name = pstring;
  }
  A(const A& pA) {
    name = pA.name + "copy";
    cout << "copy constructor of " << name << " is called" << endl;

  }
  ~A() {
    cout << "destructor of " << name << " is called" << endl;
  }
  ;
  string name;
};

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;

  int i = 0;
  vector<A> ACollection;
  string tempString;

  for (i = 0; i < 10; i++) {
    tempString = stringify(i);
    A tempA(tempString);
    ACollection.push_back(tempA);
    cout << "currently adding object " << tempString << endl;
  }
  cout << "size of the collection is " << ACollection.size() << endl;

  for (i = 0; i < 10; i++) {
    cout << ACollection[i].name << endl;
  }

  RETURN_OK();
}

}  // namespace tests13

#endif  // TESTS13_H_
