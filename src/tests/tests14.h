// tests14.h
// author: andrey.krutogolov@gmail.com
// date:   24.03.2013


#ifndef TESTS14_H_
#define TESTS14_H_

#include <memory>
#include <vector>

//using namespace std;

namespace tests14 {

int main() {

  int *i = new int;
  std::auto_ptr<int> aptr(i);

//  std::vector<std::auto_ptr<int>> v;
//  v.push_back(aptr);

  return 0;
}

}  // namespace tests14


#endif  // TESTS14_H_
