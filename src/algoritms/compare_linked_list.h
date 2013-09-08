#ifndef _COMPARE_LINKED_LISTS_H_
#define _COMPARE_LINKED_LISTS_H_

#include <iostream>

// compare linked lists
namespace compare_linked_lists {
struct SList {
  SList()
      : data(0),
        next(NULL) {
  }
  int data;
  SList * next;
};

void fill_slist(SList& list, int arr[], int length) {
  list.data = arr[0];
  SList * l1 = &list;
  for (int i = 1; i < length; i++) {
    SList* l = new SList();
    l->data = arr[i];
    l1->next = l;
    l1 = l;
  }
}

void print_slist(SList* list) {
  SList * l1 = list;
  while (l1 != NULL) {
    std::cout << l1->data << " ";
    l1 = l1->next;
  }
  std::endl(std::cout);
}

int compare_lists(struct SList *q, struct SList *r) {
  static int flag;
  std::cout << "compare_lists >" << std::endl;
  if ((q == 0) && (r == 0)) {
    flag = 1;
  } else {
    if (q == 0 || r == 0) {
      flag = 0;
    }
    if (q && r) {
      if (q->data != r->data) {
        flag = 0;
      } else {
        compare_lists(q->next, r->next);
      }
    }
  }
  return (flag);
}

int test() {
  std::cout << "Test: compare linked lists --->" << std::endl;
  SList l1, l2;
  int arr1[] = { 1, 2, 3, 4, 5 };
  int arr2[] = { 1, 2, 3, 4, 5, 6 };
  fill_slist(l1, arr1, 5);
  print_slist(&l1);
  fill_slist(l2, arr2, 6);
  print_slist(&l2);
  int compare = compare_lists(&l1, &l2);
  std::cout << " lists are ";
  if (compare) {
    std::cout << "equal";
  } else {
    std::cout << "different";
  }
  std::endl(std::cout);

  std::cout << "<--- test passed" << std::endl;
  return 1;
}
}  // namespace compare_linked_lists

#endif // _COMPARE_LINKED_LISTS_H_
