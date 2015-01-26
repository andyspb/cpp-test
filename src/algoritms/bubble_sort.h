/*
 * bubble_sort.h
 *
 *  Created on: 25 ���. 2015 �.
 *      Author: andy
 */

#ifndef BUBBLE_SORT_H_
#define BUBBLE_SORT_H_

namespace bubble_sort {

void swap(int *xp, int *yp) {
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n) {
  int i, j;
  for (i = 0; i < n; i++)
    for (j = 0; j < n - i - 1; j++)  //Last i elements are already in place
      if (arr[j] > arr[j + 1])
        swap(&arr[j], &arr[j + 1]);
}

/* Function to print an array */
void printArray(int arr[], int size) {
  int i;
  for (i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

// Driver program to test above functions
int test() {
  int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
  int n = sizeof(arr) / sizeof(arr[0]);
  bubbleSort(arr, n);
  printf("Sorted array: \n");
  printArray(arr, n);
  return 1;
}

}  // namespace bubble_sort

#endif /* BUBBLE_SORT_H_ */
