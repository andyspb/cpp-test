/*
 * count_inversions_in_array.h
 *
 *  Created on: 26 џэт. 2015 у.
 *      Author: andy
 */

#ifndef COUNT_INVERSIONS_IN_ARRAY_H_
#define COUNT_INVERSIONS_IN_ARRAY_H_

namespace count_inversions_in_array {

//Time Complexity: O(n^2)

int getInvCount(int arr[], int n) {
  int inv_count = 0;
  int i, j;

  for (i = 0; i < n - 1; i++)
    for (j = i + 1; j < n; j++)
      if (arr[i] > arr[j])
        inv_count++;

  return inv_count;
}

/* Driver progra to test above functions */
int test() {
  int arr[] = { 1, 20, 6, 4, 5 };
  printf(" Number of inversions are %d \n", getInvCount(arr, 5));
  getchar();
  return 1;
}

}  // namespace count_inversions_in_array

#endif /* COUNT_INVERSIONS_IN_ARRAY_H_ */
