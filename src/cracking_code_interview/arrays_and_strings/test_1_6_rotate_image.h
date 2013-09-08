#ifndef TEST_1_6_ROTATE_IMAGE_H_
#define TEST_1_6_ROTATE_IMAGE_H_

#include <iostream>

// Given an image represented by an NxN matrix,
// where each pixel in the image is 4 bytes,
// write a method to rotate the image by 90 degrees.
// Can you do this in place?
namespace test_1_6_rotate_image {
// The rotation can be performed in layers,
// where you perform a cyclic swap on the edges
// on each layer In the first for loop,
// we rotate the first layer (outermost edges)
// We rotate the edges by doing a four-way swap first on the corners,
// then on the element clockwise from the edges,
// then on the element three steps away
void rotate(int matrix[][2], int n) {
  for (int layer = 0; layer < n / 2; ++layer) {
    int first = layer;
    int last = n - 1 - layer;
    for (int i = first; i < last; ++i) {
      int offset = i - first;
      int top = matrix[first][i]; // save top
      // left -> top
      matrix[first][i] = matrix[last - offset][first];
      // bottom -> left
      matrix[last - offset][first] = matrix[last][last - offset];
      // right -> bottom
      matrix[last][last - offset] = matrix[i][last];
      // top -> right
      matrix[i][last] = top; // right <- saved top }
    }
  }
}

void print_N_N_matrix(int matrix[][2], int n) {
  for (int i = 0; i<n; ++i ) {
    for (int j = 0; j <n; ++j) {
      std::cout << matrix[i][j] << " ";
    }
    std::endl(std::cout);
  }
}


int test() {
  std::cout << "Test 1.6" << std::endl;
  int matrix [2][2] = {{1,2},{3,4}};
  print_N_N_matrix(matrix,2);
  rotate(matrix,2);
  print_N_N_matrix(matrix,2);
  return 1;
}
} // namespace test_1_6

#endif /* TEST_1_6_ROTATE_IMAGE_H_ */
