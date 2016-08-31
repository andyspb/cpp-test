#ifndef _ALGORITHMS_RADIX_SORT_H_
#define _ALGORITHMS_RADIX_SORT_H_

#include <iostream>

namespace radix_sort {

// C++ implementation of Radix Sort
#include<iostream>
using namespace std;

// A utility function to print an array
void print(int arr[], int n) {
  for (int i = 0; i < n; i++)
    ::std::cout << arr[i] << " ";
  ::std::cout << ::std::endl;
}

// A utility function to get maximum value in arr[]
int get_max_in_arr(int arr[], int arr_size) {
  int max = arr[0];
  if (arr_size > 1) {
    for (int i = 1; i < arr_size; ++i)
      if (arr[i] > max)
        max = arr[i];
  }
  return max;
}


// A function to do counting sort of arr[] according to
// the digit represented by exp.
void count_sort(int arr[], int arr_size, int exp) {
  int output[arr_size];  // output array
  int i, count[10] = { 0 };

  // Store count of occurrences in count[]
  for (i = 0; i < arr_size; ++i) {
    count[(arr[i] / exp) % 10]++;
  }
  std::cout << "Store count of occurrences in count[]" << std::endl;
  print(count, 10);

  // Change count[i] so that count[i] now contains actual
  //  position of this digit in output[]
  for (i = 1; i < 10; ++i) {
    count[i] += count[i - 1];
  }
  std::cout << "Change count[i] so that count[i] now contains actual position of this digit in output[]" << std::endl;
  print(count, 10);

  // Build the output array
  for (i = arr_size - 1; i >= 0; --i) {
    int t = count[(arr[i] / exp) % 10] - 1;
    int index = (arr[i] / exp) % 10;
    std::cout << "t = count["<< index << "]  - 1 "
        " output[" << t << "] = " << "arr[" << i << "]="<< arr[i]<< std::endl;
//    output[count[(arr[i] / exp) % 10] - 1] = arr[i];
    output[t] = arr[i];
    count[(arr[i] / exp) % 10]--;
  }

  // Copy the output array to arr[], so that arr[] now
  // contains sorted numbers according to current digit
  for (i = 0; i < arr_size; i++) {
    arr[i] = output[i];
  }
  print(arr, arr_size);
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radix_sort(int arr[], int n) {
  // Find the maximum number to know number of digits
  int m = get_max_in_arr(arr, n);

  // Do counting sort for every digit. Note that instead
  // of passing digit number, exp is passed. exp is 10^i
  // where i is current digit number
  for (int exp = 1; m / exp > 0; exp *= 10) {
    std::cout << "exp=" << exp << std::endl;
    count_sort(arr, n, exp);
  }
}

// Driver program to test above functions
TEST_RESULT test() {
  __SCOPE_LOG__;
//  int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
  int arr[] = { 123, 321, 213, 111, 222};
  int n = sizeof(arr) / sizeof(arr[0]);
  std::cout << "Origin array: ";
  print(arr, n);
  radix_sort(arr, n);

  std::cout << "Sorted array: ";
  print(arr, n);
  RETURN_OK();
}

}  // namespace radix_sort

#endif  // _ALGORITHMS_RADIX_SORT_H_
