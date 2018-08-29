/*
 * 1_6_rotate_image_NxN_matrix.h
 *
 *  Created on: 26 дек. 2014 г.
 *      Author: andy
 */

#ifndef _ROTATE_IMAGE_NXN_MATRIX_H_
#define _ROTATE_IMAGE_NXN_MATRIX_H_

namespace rotate_matrix {

// 1.6
//Given an image represented by an NxN matrix, where each pixel in the image is 4
//bytes, write a method to rotate the image by 90 degrees. Can you do this in place?

//SOLUTION
//Because we're rotating the matrix by 90 degrees, the easiest way to do this is to implement
//the rotation in layers. We perform a circular rotation on each layer, moving the top
//edge to the right edge, the right edge to the bottom edge, the bottom edge to the left
//edge, and the left edge to the top edge.

//Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
//column are set to 0
//This algorithm is 0(N2), which is

void print_array(int** matrix, int n) {
  if (!matrix || !*matrix)
    return;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void rotate(int** matrix, int n) {
  for (int layer = 0; layer < n / 2; ++layer) {
    int first = layer;
    int last = n - 1 - layer;
    for (int i = first; i < last; ++i) {
      int offset = i - first;
      // save top
      int top = matrix[first][i];

      // left -> top
      matrix[first][i] = matrix[last - offset][first];

      // bottom -> left
      matrix[last - offset][first] = matrix[last][last - offset];

      // right -> bottom
      matrix[last][last - offset] = matrix[i][last];

      // top -> right
      matrix[i][last] = top;
    }
  }
}

int test() {
  const int size = 4;
  int **array = new int *[size];
  for (int i = 0; i < size; i++)
    array[i] = new int[size];
  int count = 0;
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      array[i][j] = ++count;
    }
  }
  print_array(array, size);
  rotate(array, 3);
  std::cout << "after rotation" << std::endl;
  print_array(array, size);

  return 1;
}

}  // namespace rotate_matrix

#endif /* 1_6_ROTATE_IMAGE_NXN_MATRIX_H_ */
