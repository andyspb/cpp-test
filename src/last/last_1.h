/*
 * last_1.h
 *
 *  Created on: 04 но€б. 2014 г.
 *      Author: andy
 */

#ifndef LAST_1_H_
#define LAST_1_H_

//Given:
//int array A of size 10^6
//target int X
//
//Return the count of pairs (a, b) in A where a+b<=X
//
//A = [0, 1, 2, 5, 10]
//X = 4
//
//Count pairs
//(0, 1)
//(0, 2)
//(1, 2)
//
//Return: 3 pair

namespace last_1 {

void findpair(int arr[], int len, int sum) {
  ::std::sort(arr, arr + len);
  int i = 0;
  int j = len - 1;
  while (i < j) {
    while ((arr[i] + arr[j]) <= sum && i < j) {
      if ((arr[i] + arr[j]) == sum)
        std::cout << "(" << arr[i] << "," << arr[j] << ")" << std::endl;
      ++i;
    }
    --j;
    while ((arr[i] + arr[j]) >= sum && i < j) {
      if ((arr[i] + arr[j]) == sum)
        std::cout << "(" << arr[i] << "," << arr[j] << ")" << std::endl;
      j--;
    }
  }
}
int test() {
  int arr[10] = { 0, 1, 2, 5, 10 };
  findpair(arr, 5, 4);
  return 1;
}

}

#endif /* LAST_1_H_ */
