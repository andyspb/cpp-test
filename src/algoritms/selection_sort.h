/*
 * selection_sort.h
 *
 *  Created on: 25 ���. 2015 �.
 *      Author: andy
 */

#ifndef SELECTION_SORT_H_
#define SELECTION_SORT_H_

namespace selection_sort {

void swap(int *xp, int *yp) {
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void selectionSort(int arr[], int n) {
  int i, j, min_idx;

  // One by one move boundary of unsorted subarray
  for (i = 0; i < n - 1; i++) {
    // Find the minimum element in unsorted array
    min_idx = i;
    for (j = i + 1; j < n; j++)
      if (arr[j] < arr[min_idx])
        min_idx = j;

    // Swap the found minimum element with the first element
    swap(&arr[min_idx], &arr[i]);
  }
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
  int arr[] = { 64, 25, 12, 22, 11 };
  int n = sizeof(arr) / sizeof(arr[0]);
  selectionSort(arr, n);
  printf("Sorted array: \n");
  printArray(arr, n);
  return 1;
}
}

#endif /* SELECTION_SORT_H_ */
