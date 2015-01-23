/*
 * 5_2_print_binary_of_double.h
 *
 *  Created on: 09 џэт. 2015 у.
 *      Author: andy
 */

#ifndef _PRINT_BINARY_OF_DOUBLE_H_
#define _PRINT_BINARY_OF_DOUBLE_H_

//5.2 Given a real number between 0 and 7 (e.g., 0.72) that is passed in as a double, print
//the binary representation. If the number cannot be represented accurately in binary
//with at most 32 characters, print "ERROR."

#include <string>

namespace print_binary_of_double {

std::string printBinary(double num) {
  if (num >= 1 || num <= 0) {
    return "ERROR";
  }

  std::string binary;
  binary.append(".");
  while (num > 0) {
    /* Setting a limit on length: 32 characters */
    if (binary.length() >= 32) {
      std::string r("ERROR: ");
      std::string s = r + binary;  //      r.append(binary);
      return s;
    }
    double r = num * 2;
    if (r >= 1) {
      binary.append("1");
      num = r - 1;
    } else {
      binary.append("0");
      num = r;
    }
  }
  return binary;
}

std::string printBinary2(double num) {
  if (num >= 1 || num <= 0) {
    return "ERROR";
  }

  std::string binary;
  double frac = 0.5;
  binary.append(".");
  while (num > 0) {
    /* Setting a limit on length: 32 characters */
    if (binary.length() > 32) {
      std::string r("ERROR: ");
      std::string s = r + binary;  //      r.append(binary);
      return s;
    }
    if (num >= frac) {
      binary.append("1");
      num -= frac;
    } else {
      binary.append("0");
    }
    frac /= 2;
  }
  return binary;
}

int test() {
  std::cout << "print_binary_of_double:\n";

  for (double b = 0.2; b < 0.9; b += 0.05) {
    std::cout << b << " = " << printBinary(b) << std::endl;
    std::cout << b << " = " << printBinary2(b) << std::endl;
  }
  return 1;
}

}

#endif /* 5_2_PRINT_BINARY_OF_DOUBLE_H_ */
