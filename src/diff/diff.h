/*
 * diff.h
 *
 *  Created on: Aug 13, 2015
 *      Author: andy
 */

#ifndef SRC_DIFF_DIFF_H_
#define SRC_DIFF_DIFF_H_

#include <iostream>

namespace diff {

constexpr char file1[] = "This long piece of text will have a "
    "common part found by LCS.\n";

constexpr char file2[] = "This extra long piece of text will "
    "have some common parts found by LCS.\n";

TEST_RESULT test() {
  __SCOPE_LOG__;
  std::cout << "file1:\n" << file1;
  std::cout << "file2:\n" << file2;
  RETURN_OK();
}

}

#endif /* SRC_DIFF_DIFF_H_ */
