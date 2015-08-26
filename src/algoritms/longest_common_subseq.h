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

/* Utility function to get max of 2 integers */
int max(int a, int b) {
  return (a > b) ? a : b;
}

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs_rec(const std::string& X, const std::string& Y, int m, int n) {
  if (m == 0 || n == 0)
    return 0;
  if (X[m - 1] == Y[n - 1])
    return 1 + lcs_rec(X, Y, m - 1, n - 1);
  else
    return max(lcs_rec(X, Y, m, n - 1), lcs_rec(X, Y, m - 1, n));
}

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
void lcs(const std::string& str1, const std::string& str2) {
  size_t i, j, size1 = str1.size(), size2 = str2.size();

  // Size of columns is based on the size of the biggest string
  int max_size = (size1 < size2) ? size2 : size1;

  //  warning: array of array of runtime bound [-Wvla]
  //int temp[size1 + 1][size2 + 1];

  int **temp = new int*[max_size];
  for (int i = 0; i < max_size; ++i) {
    temp[i] = new int[max_size];
  }

  /* Following steps build L[m+1][n+1] in bottom up fashion. Note
   that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
  for (i = 0; i <= size1; i++) {
    for (j = 0; j <= size2; j++) {
      if (i == 0 || j == 0) {
        // for zero indexes set 0
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
  std::cout << "LCS of \n" << str1 << "\n" << str2 << "\nis " << lcs
            << std::endl;

  for (int i = 0; i < max_size; ++i) {
    delete[] temp[i];
  }
  delete[] temp;
}

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;

  std::string str1 = "AGGTAB";
  std::string str2 = "GXTXAYB";
  lcs(str1, str2);

  std::string X = "AGGTAB";
  std::string Y = "GXTXAYB";

  int m = X.size();
  int n = Y.size();

  std::cout << "Length of LCS is " << lcs_rec(X, Y, m, n) << std::endl;

  RETURN_OK();
}

}  // namespace longest_common_subseq

#endif /* SRC_ALGORITMS_LONGEST_COMMON_SUBSEQ_H_ */
