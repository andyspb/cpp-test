/*
 * fastscan.h
 *
 *  Created on: Apr 24, 2017
 *      Author: andy
 */

#ifndef SRC_FAST_IO_FAST_SCAN_H_
#define SRC_FAST_IO_FAST_SCAN_H_

#include <iostream>

namespace fast_scan {

void fastscan(int &number) {
  //variable to indicate sign of input number
  bool negative = false;
  register int c;

  number = 0;

  // extract current character from buffer
  c = getchar();
  if (c == '-') {
    // number is negative
    negative = true;

    // extract the next character from the buffer
    c = getchar();
  }

  // Keep on extracting characters if they are integers
  // i.e ASCII Value lies from '0'(48) to '9' (57)
  for (; (c > 47 && c < 58); c = getchar())
    number = number * 10 + c - 48;

  // if scanned input has a negative sign, negate the
  // value of the input number
  if (negative)
    number *= -1;
}

TEST_RESULT test() {
  int number;
  fastscan(number);
  std::cout << number << "\n";
  RETURN_OK();
}

}  // namespace fast_scan

#endif /* SRC_FAST_IO_FAST_SCAN_H_ */
