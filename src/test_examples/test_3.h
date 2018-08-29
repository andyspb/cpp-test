//  test3.h
//  author: andrey.krutogolov@gmail.com
//  date:   10.03.2013

#ifndef TEST3_H_
#define TEST3_H_

#include <stdio.h>

namespace test_3 {

typedef void (*UserFunc)(int& p1, int p2);

void ModifyArrayElements(int *arr, int size, int param, UserFunc func) {
  if (!arr || size <= 0) {
    /* incorrect data */
    return;
  }
  if (!func) {
    /* incorrect user func */
    return;
  }
  int i(0);
  for (; i < size; ++i) {
    func(arr[i], param);
  }
}

void Increment(int& arg, int value) {
  arg += value;
}

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;

  std::cout << "Test3: " << std::endl;
  int arr[] = { 1, 2, 3, 4, 5 };
  for (int i = 0; i < 5; ++i) {
    printf("%d ", arr[i]);
  }
  printf("%c", '\n');
  ModifyArrayElements(arr, 5, 1, Increment);
  for (int i = 0; i < 5; ++i) {
    printf("%d ", arr[i]);
  }
  printf("%c", '\n');
  RETURN_OK();
}

}  // namespace test3

#endif  // TEST3_H_
