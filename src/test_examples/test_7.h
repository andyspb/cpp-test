//  tests7.h
//  author: andrey.krutogolov@gmail.com
//  date:   19.03.2013

#ifndef TESTS7_H_
#define TESTS7_H_

#include <list>
#include <vector>
#include <map>

namespace test_7 {

TEST_RESULT test() {
  __SCOPE_LOG__;

  std::list<int> l;
  std::vector<int> v;
  std::set<int> s;

  std::sort(v.begin(), v.end());
  l.sort();

  RETURN_OK();
}

}  // namespace tests7

#endif  // TESTS7_H_
