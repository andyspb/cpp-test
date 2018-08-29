#ifndef TEST_2_3_DELETE_IN_MIDDLE_SLIST_H_
#define TEST_2_3_DELETE_IN_MIDDLE_SLIST_H_
// Implement an algorithm to delete a node in the middle of a single linked list, given only access to that node
// EXAMPLE
// Input: the node ÔcÕ from the linked list a->b->c->d->e
// Result: nothing is returned, but the new linked list looks like a->b->d->e

namespace test_2_3 {
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

// The solution to this is to simply copy the data from the next node
// into this node and then delete the next node

bool deleteNode(LList *node) {
  if (node == NULL || node->next == NULL) {
    return false;
  }
  LList *temp = node->next;
  node->data = temp->data;
  node->next = temp->next;
  return true;
}

int test() {
  std::cout << "Test 2.3" << std::endl;
  LList list(0);
  fill_list(&list);
  print_list(&list);
  LList *node = &list;
  for (int i = 0; i < 4; ++i) {
    node = node->next;
  }
  if (deleteNode(node)) {
    print_list(&list);
  }
  return 1;
}

}  // namespace test_2_3

#endif /* TEST_2_3_DELETE_IN_MIDDLE_SLIST_H_ */
