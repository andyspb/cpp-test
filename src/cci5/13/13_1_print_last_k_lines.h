/*
 * 13_1_print_last_k_lines.h
 *
 *  Created on: 05 џэт. 2015 у.
 *      Author: andy
 */

#ifndef _PRINT_LAST_K_LINES_H_
#define _PRINT_LAST_K_LINES_H_

#include <fstream>>
#include <string>
#include <algorithm>

namespace print_last_k_lines {

void printLastl0Lines(char* fileName) {
  const int K = 10;
  std::ifstream file(fileName);
  std::string L[K];
  int size = 0;

  /* read file line by line into circular array */
  while (file.good()) {
    getline(file, L[size % K]);
    ++size;
  }

  // compute start of circular array, and the size of it
  int start = size > K ? (size % K) : 0;
  int count = std::min(K, size);

  /* print elements in the order they were read */
  for (int i = 0; i < count; i++) {
    std::cout << L[(start + i) % K] << std::endl;
  }
}

int test() {
  char * test_file = "c:\\test.txt";
  printLastl0Lines(test_file);
  return 1;
}

}  // namespace print_last_k_lines

#endif /* 13_1_PRINT_LAST_K_LINES_H_ */
