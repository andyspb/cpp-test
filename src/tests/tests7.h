//  tests7.h
//  author: andrey.krutogolov@gmail.com
//  date:   19.03.2013


#ifndef TESTS7_H_
#define TESTS7_H_

#include <list>
#include <vector>
#include <map>

using namespace std;


namespace tests7 {

int main() {
  list<int> l;
  vector<int> v;
  set<int> s;

  std::sort(v.begin(), v.end());
  l.sort();

  return 0;
}


}  // namespace tests7

#endif  // TESTS7_H_
