#ifndef TEST_2_1_REMOVE_DUPLICATES_FROM_UNSORTED_LINKED_LIST_H_
#define TEST_2_1_REMOVE_DUPLICATES_FROM_UNSORTED_LINKED_LIST_H_

#include <iostream>
#include <set>

#include <iostream>
// Write code to remove duplicates from an unsorted linked list
// FOLLOW UP
// How would you solve this problem if a temporary buffer is not allowed?
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
namespace test_2_1 {
// If we can use a buffer, we can keep track of elements
// in a hashtable and remove any dups:
void deleteDups(LList *head) {
  if (!head && !head->next) {
    return;
  }
  // need use hash table O(1)
  // for set O(log n)
  std::set<int> myset;
  LList *prev = NULL;
  while (head != NULL) {
    if (myset.find(head->data) != myset.end()) {
      prev->next = head->next;
    } else {
      myset.insert(head->data);
      prev = head;
    }
    head = head->next;
  }
}

// Without a buffer, we can iterate with two pointers: ÒcurrentÓ does a normal
// iteration, while ÒrunnerÓ iterates through all prior nodes to check
// for dups Runner will only see one dup per node, because if there were
// multiple duplicates they would have been removed already
void deleteDup2(LList * head) {
  if (!head && !head->next) {
    return;
  }
  LList *prev = head;
  LList *current = prev->next;
  while (current) {
    LList *runner = head;
    while (runner != current) {
      if (runner->data == current->data) {  // Check for earlier dups
        LList *tmp = current->next;  // remove current
        prev->next = tmp;  // update current to next node
        current = tmp;  // all other dups have already been removed
        break;
      }
      runner = runner->next;
    }
    if (runner == current) {  // current not updated - update now
      prev = current;
      current = current->next;
    }
  }
}

int test() {
  std::cout << "Test 2.1" << std::endl;
  LList list(0);
  fill_list(&list);
  print_list(&list);
  deleteDups(&list);
  print_list(&list);

  LList list1(0);
  fill_list(&list1);
  print_list(&list1);
  deleteDups(&list1);
  print_list(&list1);

  return 1;
}

}  // namespace test_2_1

#endif /* TEST_2_1_REMOVE_DUPLICATES_FROM_UNSORTED_LINKED_LIST_H_ */
