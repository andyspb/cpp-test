//  test2.h
//  author: andrey.krutogolov@gmail.com
//  date:   10.03.2013

#ifndef TEST2_H_
#define TEST2_H_

#include <iostream>

namespace test_2 {

/* suppose to use int as struct data*/
struct DList {
  int value;
  DList *prev, *next;
};

/* function take 2 params - pointer to an array and its size*/
DList* ArrayToDList(int* arr, int size) {
  if (!arr || size <= 0) {
    /* incorrect input*/
    return 0;
  }
  int i(0);
  /* using calloc, it set all zeros*/
  DList* head = (DList*) calloc(1, sizeof(DList));
  /* assume that calling calloc is fine here and below*/
  head->value = arr[i];
  DList* tail = head;
  for (i = 1; i < size; ++i) {
    DList* temp = (DList*) calloc(1, sizeof(DList));
    temp->value = arr[i];
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
  }
  return head;
}

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;

  std::cout << "Test2" << std::endl;

  int arr[] = { 3, 4, 5, 6 };
  DList* l = ArrayToDList(arr, 5);

  while (l) {
    std::cout << l->value << " ";
    l = l->next;
  }

  std::endl(std::cout);
  RETURN_OK();
}

}  // namespace test2

#endif  // TEST2_H_
