#include <iostream>
#include <list>
#include <algorithm>

bool IsFive(int i) {
  return (i == 5);
}

namespace list_find {
void test() {
  std::list<int> l;
  for (int i = 0; i < 20; ++i) {
    l.push_back(i);
  }

  std::list<int>::iterator find = find_if(l.begin(), l.end(), IsFive);
  if (find != l.end()) {
    std::cout << "5 found->" << *find << std::endl;
  } else {
    std::cout << "5 not found" << *find << std::endl;
  }
}
}
