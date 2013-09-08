#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

bool IsFive(int i) {
  return (i == 5);
}

namespace list_find {
void test() {

  list<int> l;
  for (int i = 0; i < 20; ++i) {
    l.push_back(i);
  }

  list<int>::iterator find = find_if(l.begin(), l.end(), IsFive);

  if (find != l.end()) {
    cout << "5 found->" << *find << endl;
  } else {
    cout << "5 not found" << *find << endl;
  }
}
}
