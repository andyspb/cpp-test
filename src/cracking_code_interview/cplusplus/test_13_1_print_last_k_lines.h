//One brute force way could be to count the number of lines (N)
//and then print from N-10 to Nth line. But, this requires two reads of the
//file – potentially very costly if the file is large.
//We need a solution which allows us to read just once and be able to print the
//last K lines. We can create extra space for K lines and then store each set of
//K lines in the array. So, initially, our array has lines 0 through 9, then 1
//through 10, then 2 through 11, etc (if K = 10). Each time that we read a new
//line, we purge the oldest line from the array. Instead of shifting the array
//each time (very inefficient), we will use a circular array. This will allow us
//to always find the oldest element in O(1) time.
#ifndef TEST_13_1_PRINT_LAST_K_LINES_H_
#define TEST_13_1_PRINT_LAST_K_LINES_H_

#include <fstream>
#include <iostream>
#include <string>

//step 1 (initially): array = {a, b, c, d, e, f}. p = 0
//step 2 (insert g): array = {g, b, c, d, e, f}. p = 1
//step 3 (insert h): array = {g, h, c, d, e, f}. p = 2
//step 4 (insert i): array = {g, h, i, d, e, f}. p = 3

namespace test_13_1_print_last_k_lines {

void f(int K, const char* file_name ) {
  std::string L[K];
  int lines = 0;
  std::fstream file(file_name);
  if (!file.good()) {
    std::cout << file_name << "was not opened correctly" << std::endl;
  }
  while (file.good()) {
    std::getline(file, L[lines % K]); // read file line by line
    ++lines;
  }
  // if less than K lines were read, print them all
  int start, count;
  if (lines < K) {
    start = 0;
    count = lines;
  } else {
    start = lines % K;
    count = K;
  }
  for (int i = 0; i < count; ++i) {
    std::cout << L[(start + i) % K] << std::endl;
  }
}

int test() {
  std::cout << "Read last k lines from file" << std::endl;
  f(5, "test.txt");
  return 1;
}
}  // namespace test_13_1_print_last_k_lines

#endif /* TEST_13_1_PRINT_LAST_K_LINES_H_ */
