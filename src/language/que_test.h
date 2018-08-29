#ifndef _QUE_TEST_H_
#define _QUE_TEST_H_

#include <iostream>
#include <queue>
namespace que_test {

int test() {
  std::cout << "Test: que test --->" << std::endl;
  std::queue<int> que;
  std::cout << "\tpushing data: ";
  for (int i = 1; i < 10; ++i) {
    que.push(i);
    std::cout << i << " ";
  }
  std::endl(std::cout);
  std::cout << "\tpop data: ";
  while (!que.empty()) {
    std::cout << que.front() << " ";
    que.pop();
  }
  std::endl(std::cout);
  std::cout << "<--- passed" << std::endl;
  return 1;
}
}  // namespace que_test
#endif // _QUE_TEST_H_
