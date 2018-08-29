#ifndef TEST_2_2_FIND_NTH_TO_LAST_ELEMENT_OF_SLIST_H_
#define TEST_2_2_FIND_NTH_TO_LAST_ELEMENT_OF_SLIST_H_

// Implement an algorithm to find the nth to last element
// of a singly linked list

namespace test_2_2 {
struct LList {
  LList(int d)
      : data(d),
        next(NULL) {
  }
  int data;
  LList *next;
};

void fill_list(LList *head) {
  LList *temp = head;
  for (int i = 1; i < 10; ++i) {
    int data = i;
    if (i == 3 || i == 6 || i == 8) {
      data = data - 1;
    }
    LList * n = new LList(data);
    temp->next = n;
    temp = n;
  }
}

void print_list(LList *head) {
  LList *temp = head;
  while (temp) {
    std::cout << temp->data << " ";
    temp = temp->next;
  }
  std::endl(std::cout);
}

LList *nthToLast(LList *head, int n) {
  if (head == NULL || n < 1) {
    return NULL;
  }
  LList* p1 = head;
  LList* p2 = head;
  for (int j = 0; j < n - 1; ++j) {  // skip n-1 steps ahead
    if (p2 == NULL) {
      return NULL;  // not found since list size < n }
    }
    p2 = p2->next;
  }
  while (p2->next != NULL) {
    p1 = p1->next;
    p2 = p2->next;
  }
  return p1;
}

int test() {
  std::cout << "Test 2.2" << std::endl;
  LList list(0);
  fill_list(&list);
  print_list(&list);
  LList *nth = nthToLast(&list, 5);
  print_list(nth);
  return 1;
}
}  // test_2_2

#endif /* TEST_2_2_FIND_NTH_TO_LAST_ELEMENT_OF_SLIST_H_ */
