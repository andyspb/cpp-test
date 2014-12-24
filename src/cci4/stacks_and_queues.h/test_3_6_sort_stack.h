#ifndef TEST_3_6_SORT_STACK_H_
#define TEST_3_6_SORT_STACK_H_

#include <stack>
#include <iostream>

namespace test_3_6 {
// Sorting can be performed with one more stack.
// The idea is to pull an item from the original stack and
// push it on the other stack.
// If pushing this item would violate the sort order of the new stack,
// we need to remove enough items from it so that its possible to push the
// new item Since the items we removed are on the original stack,
// we’re back where we started The algorithm is O(N^2) and appears below
std::stack<int>* sort(std::stack<int>& s) {
  std::stack<int>* r = new std::stack<int>();
  while (!s.empty()) {
    int tmp = s.top();
    s.pop();
    while (!r->empty() && r->top() > tmp) {
      int val = r->top();
      s.push(val);
      r->pop();
    }
    r->push(tmp);
  }
  return r;
}

int test() {
  std::cout << "Test 3.6" << std::endl;
  std::stack<int> s;
  s.push(1);
  s.push(7);
  s.push(5);
  s.push(3);
  s.push(4);

  std::stack<int> * ss = sort(s);
  while (ss && !ss->empty()) {
    int v = ss->top();
    ss->pop();
    std::cout << v << " ";
  }
  std::endl(std::cout);
  return 1;
}
} // namespace test_3_6
#endif /* TEST_3_6_SORT_STACK_H_ */
