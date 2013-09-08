#ifndef TEST_2_4_SUM_LINKED_LIST_H_
#define TEST_2_4_SUM_LINKED_LIST_H_
// You have two numbers represented by a linked list,
// where each node contains a single digit.
// The digits are stored in reverse order,
// such that the 1Õs digit is at the head of the list.
// Write a function that adds the two numbers
// and returns the sum as a linked list
// EXAMPLE
// Input: (3 -> 1 -> 5) + (5 -> 9 -> 2)
// Output: 8 -> 0 -> 8

namespace test_2_4 {
struct LList {
    LList(int d)
        : data(d), next(NULL) {
    }
    int data;
    LList *next;
};

void test_fill_list1(LList *head) {
  LList *temp = head;
  LList * n = new LList(3);
  temp->next = n;
  temp = n;
  n = new LList(1);
  temp->next = n;
  temp = n;
  n = new LList(5);
  temp->next = n;
  temp = n;
}

void test_fill_list2(LList *head) {
  LList *temp = head;
  LList * n = new LList(5);
  temp->next = n;
  temp = n;
  n = new LList(9);
  temp->next = n;
  temp = n;
  n = new LList(2);
  temp->next = n;
  temp = n;
}

void print_list(LList *head) {
  LList *temp = head;
  while (temp) {
    std::cout << temp->data << " ";
    temp = temp->next;
  }
  std::endl(std::cout);
}

LList *addLists(LList *l1, LList *l2, int carry) {
  if (l1 == NULL && l2 == NULL ) {
    return NULL;
  }
  LList *result = new LList(carry);
  int value = carry;
  if (l1 != NULL) {
    value += l1->data;
  }
  if (l2 != NULL) {
    value += l2->data;
  }
  result->data = value % 10;
  LList *more = addLists(l1 == NULL ? NULL : l1->next,
      l2 == NULL ? NULL : l2->next, value >= 10 ? 1 : 0);
  result->next = more;
  return result;
}

 // We can implement this recursively by adding node by node,
// just as we would digit by digit
// result data = (node1 + node2 + any earlier carry) % 10
// if node1 + node2 > 10, then carry a 1 to the next addition
// add the tails of the two nodes, passing along the carry

int test() {
  std::cout << "Test 2.4" << std::endl;
  LList list1(0);
  test_fill_list1(&list1);
  print_list(&list1);
  LList list2(0);
  test_fill_list2(&list2);
  print_list(&list2);
  LList *sum = addLists(&list1, &list2, 0);
  print_list(sum);
  return 1;
}

} // namesapce namespace test_2_4

#endif /* TEST_2_4_SUM_LINKED_LIST_H_ */
