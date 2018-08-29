/*
 * 13_10_malloc_2d_array.h
 *
 *  Created on: 05 џэт. 2015 у.
 *      Author: andy
 */

#ifndef _MALLOC_2D_ARRAY_H_
#define _MALLOC_2D_ARRAY_H_

namespace malloc_2d_arr {

int** my2DAlloc(int rows, int cols) {
  int** rowptr;
  int i;
  rowptr = (int**) malloc(rows * sizeof(int*));
  for (i = 0; i < rows; i++) {
    rowptr[i] = (int*) malloc(cols * sizeof(int));
  }
  return rowptr;
}

void my2DDealloc(int** rowptr, int rows) {
  for (i = 0; i < rows; i++) {
    free(rowptr[i]);
  }
  free(rowptr);
}

int** my2DAlloc_singlemalloc(int rows, int cols) {
  int i;
  int header = rows * sizeof(int*);
  int data = rows * cols * sizeof(int);
  int** rowptr = (int**) malloc(header + data);
  if (rowptr == 0)
    return 0;

  int* buf = (int*) (rowptr + rows);
  for (i = 0; i < rows; ++i) {
    rowptr[i] = buf + i * cols;
  }
  return rowptr;
}

int test() {
  return 1;
}

}  // namespace malloc_2d_arr

#endif /* _MALLOC_2D_ARRAY_H_ */
