/*
 * array_2d.h
 *
 *  Created on: May 24, 2016
 *      Author: andy
 */

#ifndef SRC_ARRAY_ARRAY_2D_H_
#define SRC_ARRAY_ARRAY_2D_H_

namespace array_2d {

TEST_RESULT allocate_2d() {
  __SCOPE_LOG__;

  int row = 3, column = 4;
  int *arr = (int *) malloc(row * column * sizeof(int));
  int i, j, count = 100;

  for (i = 0; i < row; i++)
    for (j = 0; j < column; j++)
      *(arr + i * column + j) = ++count;

  for (i = 0; i < row; i++) {
    for (j = 0; j < column; j++) {
      printf("%d ", *(arr + i * column + j));
    }
    printf("%s", "\n");
  }
  /* Code for further processing and free the
   dynamically allocated memory */

  RETURN_OK();
}

TEST_RESULT allocate_2d_1() {
  __SCOPE_LOG__;

  const int r = 3;
  int c = 4, i, j, count;

  int *arr[r];
  for (i = 0; i < r; i++)
    arr[i] = (int *) malloc(c * sizeof(int));

  // Note that arr[i][j] is same as *(*(arr+i)+j)
  count = 0;
  for (i = 0; i < r; i++)
    for (j = 0; j < c; j++)
      arr[i][j] = ++count;  // Or *(*(arr+i)+j) = ++count

  for (i = 0; i < r; i++) {
    for (j = 0; j < c; j++)
      printf("%d ", arr[i][j]);
    printf("%s", "\n");
  }
  /* Code for further processing and free the
   dynamically allocated memory */

  RETURN_OK();
}

TEST_RESULT test() {
  __SCOPE_LOG__;

  allocate_2d();
  allocate_2d_1();

  RETURN_OK();
}

}  // namespace array_2d

#endif /* SRC_ARRAY_ARRAY_2D_H_ */
