/*
 * longest_common_subseq.h
 *
 *  Created on: Aug 24, 2015
 *      Author: andy
 */

#ifndef SRC_ALGORITMS_LONGEST_COMMON_SUBSEQ_H_
#define SRC_ALGORITMS_LONGEST_COMMON_SUBSEQ_H_

#include <iostream>
#include <cstring>
#include <cstdlib>

namespace longest_common_subseq {

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
void lcs(const std::string& str1, const std::string& str2) {
  size_t i, j, size1 = str1.size(), size2 = str2.size();

  // Size of columns is based on the size of the biggest string
  int max_size = (size1 < size2) ? size2 : size1;

  int temp[size1 + 1][size2 + 1];

  /* Following steps build L[m+1][n+1] in bottom up fashion. Note
   that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
  for (i = 0; i <= size1; i++) {
    for (j = 0; j <= size2; j++) {
      if (i == 0 || j == 0) {
        temp[i][j] = 0;
      } else if (str1[i - 1] == str2[j - 1]) {
        temp[i][j] = temp[i - 1][j - 1] + 1;
      } else {
        temp[i][j] = max(temp[i - 1][j], temp[i][j - 1]);
      }
    }
  }

  // Following code is used to print LCS
  int index = temp[size1][size2];

  // Create a character array to store the lcs string
  char lcs[index + 1];
  lcs[index] = '\0';  // Set the terminating character

  // Start from the right-most-bottom-most corner and
  // one by one store characters in lcs[]
  i = size1, j = size2;
  while (i > 0 && j > 0) {
    // If current character in X[] and Y are same, then
    // current character is part of LCS
    if (str1[i - 1] == str2[j - 1]) {
      lcs[index - 1] = str1[i - 1];  // Put current character in result
      i--;
      j--;
      index--;     // reduce values of i, j and index
    }

    // If not same, then find the larger of two and
    // go in the direction of larger value
    else if (temp[i - 1][j] > temp[i][j - 1])
      i--;
    else
      j--;
  }

  // Print the lcs
  cout << "LCS of " << str1 << " and " << str2 << " is " << lcs;
}

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;

  std::string str1 = "AGGTAB";
  std::string str2 = "GXTXAYB";
  lcs(str1, str2);

  RETURN_OK();
}

}  // namespace longest_common_subseq

#endif /* SRC_ALGORITMS_LONGEST_COMMON_SUBSEQ_H_ */
