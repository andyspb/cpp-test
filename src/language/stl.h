#pragma once

using namespace std;
namespace stl_test {
void test() {
  list<int> ls;
  int i = 0;
  while (i < 20) {
    ls.push_back(++i);
  }
  ls.erase(remove(ls.begin(), ls.end(), 2), ls.end());

  return;
}

}
