#ifndef TEST_1_7_IF_ELEMENT_MATRIX_IS_0_ENTIRE_ROW_AND_COLUMN_SET_0_H_
#define TEST_1_7_IF_ELEMENT_MATRIX_IS_0_ENTIRE_ROW_AND_COLUMN_SET_0_H_
// Write an algorithm such that if an element in an MxN matrix is 0,
// its entire row and column is set to 0

namespace test_1_7_if_element_matrix_is_0_entire_row_and_column_set_0 {
// At first glance, this problem seems easy: just iterate through the matrix
// and every time we see a 0, set that row and column to 0.
// There’s one problem with that solution though: we will “recognize”
// those 0s later on in our iteration and then set their row and column to zero
// Pretty soon, our entire matrix is 0s!
// One way around this is to keep a second matrix which flags the 0 locations
// We would then do a second pass through the matrix to set the zeros
// This would take O(MN) space
// Do we really need O(MN) space? No Since we’re going to set the entire row
// and column to zero, do we really need to track which cell in a row is zero?
// No We only need to know that row 2, for example, has a zero
// The code below implement this algorithm We keep track in two arrays all
// the rows with zeros and all the columns with zeros
// We then make a second pass oft hematrix
// and set a cell to zero if its row or column is zero
void setZeros(int matrix[][2], int m, int n) {
  int row[3] = { 0 };
  int column[2] = { 0 };
  // Store the row and column index with value 0
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (matrix[i][j] == 0) {
        row[i] = 1;
        column[j] = 1;
      }
    }
  }
  // Set arr[i][j] to 0 if either row i or column j has a 0
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if ((row[i] == 1 || column[j] == 1)) {
        matrix[i][j] = 0;
      }
    }
  }
}

void print_N_N_matrix(int matrix[][2], int m, int n) {
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cout << matrix[i][j] << " ";
    }
    std::endl(std::cout);
  }
}

int test() {
  std::cout << "Test 1.7" << std::endl;
  int matrix[3][2] = { { 1, 2 }, { 1, 0 }, { 3, 4 } };
  print_N_N_matrix(matrix, 3, 2);
  setZeros(matrix, 3, 2);
  print_N_N_matrix(matrix, 3, 2);
  return 1;
}
}

#endif /* TEST_1_7_IF_ELEMENT_MATRIX_IS_0_ENTIRE_ROW_AND_COLUMN_SET_0_H_ */
