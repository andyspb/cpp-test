#ifndef _STD_QSORT_H_
#define _STD_QSORT_H_

/* qsort example */
#include <iostream>
#include <stdlib.h>

namespace std_qsort {

int values[] = { 40, 10, 100, 90, 20, 25, -1 };

int compare(const void * a, const void * b) {
  return (*(int*) a - *(int*) b);
}

int test() {
  std::cout << "Test: std::qsort --->" << std::endl;
  int n = 0;
  for (n = 0; n < 7; n++) {
    std::cout << values[n] << "  ";
  }
  std::endl(std::cout);
  qsort(values, 6, sizeof(int), compare);
  for (n = 0; n < 7; n++) {
    std::cout << values[n] << " ";
  }
  std::endl(std::cout);
  return 1;
}
}  // namespace std_qsort

#endif // _STD_QSORT_H_
