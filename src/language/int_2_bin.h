//19.	Write a method to print binary form of an integer
//
#include <string>
#include <iostream>
#include <limits>

void Int2Bin(int i) {
  char bin[32];
  itoa(i, bin, 2);

  printf("integer %d binary %s\n", i, bin);
}

void binary(int number) {
  int remainder;

  if (number <= 1) {
    std::cout << number;
    return;
  }

  remainder = number % 2;
  binary(number >> 1);
  std::cout << remainder;
}
