#ifndef __STL_H__
#define __STL_H__

namespace stl_test {
void test() {
  std::list<int> ls;
  int i = 0;
  while (i < 20) {
    ls.push_back(++i);
  }
  ls.erase(remove(ls.begin(), ls.end(), 2), ls.end());
  return;
}
}  // anmespace stl_test

#endif  // __STL_H__
