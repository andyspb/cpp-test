#ifndef INSERTSORT_H_
#define INSERTSORT_H_
/**
 *  Simple implementation
 Efficient for (quite) small data sets
 Adaptive (i.e., efficient) for data sets that are already substantially sorted: the time complexity is O(n + d), where d is the number of inversions
 More efficient in practice than most other simple quadratic (i.e., O(n2)) algorithms such as selection sort or bubble sort; the best case (nearly sorted input) is O(n)
 Stable; i.e., does not change the relative order of elements with equal keys
 In-place; i.e., only requires a constant amount O(1) of additional memory space
 Online; i.e., can sort a list as it receives it but for the same work the selection sort needs more time which makes it less efficient.
 *
 */

#include <iostream>

namespace insertsort {
struct SList {
  SList(int i)
      : val_(i),
        next_(0) {
  }
  int val_;
  struct SList * next_;
};

struct SList *SortList(struct SList * pList) {
  // build up the sorted array from the empty list
  struct SList *pSorted = NULL;
  // take items off the input list one by one until empty
  while (pList != NULL) {
    // remember the head
    struct SList *pHead = pList;
    // trailing pointer for efficient splice
    struct SList **ppTrail = &pSorted;
    //pop head off list
    pList = pList->next_;
    //splice head into sorted list at proper place
    while (true) {
      // does head belong here?
      if (*ppTrail == NULL || pHead->val_ < (*ppTrail)->val_) {
        pHead->next_ = *ppTrail;
        *ppTrail = pHead;
        break;
      } else {
        ppTrail = &(*ppTrail)->next_;
      }
    }
  }
  return pSorted;
}

void fill_slist(SList * head) {
  if (!head) {
    return;
  }
  SList *temp = head;
  int arr[14] = { 9, 2, 34, 5, 34, 0, 2, 3, 4, 7, 8, 77, 1, 5 };
  for (int i = 0; i < 14; ++i) {
    temp->next_ = new SList(arr[i]);
    temp = temp->next_;
  }
}

void print_slist(SList * head) {
  if (!head) {
    return;
  }
  SList * temp = head;
  while (temp) {
    std::cout << temp->val_ << " ";
    temp = temp->next_;
  }
  std::endl(std::cout);
  return;
}

int test() {
  std::cout << "Test: insertsort test --->" << std::endl;
  SList sl(-1);
  fill_slist(&sl);
  print_slist(&sl);
  SortList(&sl);
  print_slist(&sl);
  std::cout << "<--- test passed" << std::endl;
  return 1;
}

}  // namespace insertsort

#endif /* INSERTSORT_H_ */
