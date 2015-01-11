/*
 * 11_1_merge_array_to_array.h
 *
 *  Created on: 05 џэт. 2015 у.
 *      Author: andy
 */

#ifndef _MERGE_ARRAY_TO_ARRAY_H_
#define _MERGE_ARRAY_TO_ARRAY_H_

namespace merge_array_to_array {

void merge(int a[], int b[], int lastA, int lastB) {
  int indexA = lastA - 1; /* Index of last element in array a */
  int indexB = lastB - 1; /* Index of last element in array b */
  int indexMerged = lastB + lastA - 1; /* end of merged array */

  /* Merge a and b, starting from the last element in each */
  while (indexA >= 0 && indexB >= 0) {
    /* end of a is > than end of b */
    if (a[indexA] > b[indexB]) {
      a[indexMerged] = a[indexA]; // copy element
      indexMerged--; // move indices
      indexA--;
    } else {
      a[indexMerged] = b[indexB]; // copy element
      indexMerged--; // move indices
      indexB--;
    }
  }

  /* Copy remaining elements from b into place */
  while (indexB >= 0) {
    a[indexMerged] = b[indexB];
    indexMerged--;
    indexB--;
    }
  }

int test() {
  return 1;
}

}  // namespace merge_array_to_array



#endif /* 11_1_MERGE_ARRAY_TO_ARRAY_H_ */
