/*
 * array.h
 *
 *  Created on: Nov 17, 2014
 *      Author: andy
 */

#ifndef ARRAY_H_
#define ARRAY_H_

#include <stdio.h>
#include <stdlib.h>

namespace array {

int test() {
    int row = 3, column = 4;
    int *arr = (int *)malloc(row * column * sizeof(int));
    int i, j, count = 100;

    for (i = 0; i < row; i++)
      for (j = 0; j < column; j++)
         *(arr + i*column + j) = ++count;

    for (i = 0; i < row; i++) {
      for (j = 0; j < column; j++)
         printf("%d ", *(arr + i*column + j));
      printf("%s", "\n");
    }
   /* Code for further processing and free the
      dynamically allocated memory */

   return 1;
}


int test1()
{
    int r = 3, c = 4, i, j, count;

    int *arr[r];
    for (i=0; i<r; i++)
         arr[i] = (int *)malloc(c * sizeof(int));

    // Note that arr[i][j] is same as *(*(arr+i)+j)
    count = 0;
    for (i = 0; i <  r; i++)
      for (j = 0; j < c; j++)
         arr[i][j] = ++count; // Or *(*(arr+i)+j) = ++count

    for (i = 0; i <  r; i++) {
      for (j = 0; j < c; j++)
        printf("%d ", arr[i][j]);
      printf("%s", "\n");
    }
    /* Code for further processing and free the
      dynamically allocated memory */

   return 1;
}

} // namespace array

#endif /* ARRAY_H_ */
