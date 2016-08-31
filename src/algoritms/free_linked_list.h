#ifndef _FREE_LINKED_LIST_H_
#define _FREE_LINKED_LIST_H_

#include <iostream>

namespace free_linkedlist {
class List {
  public:
    List(int v)
        : value(v), next(NULL) {
    }
    ~List() {
      std::cout << "from LList::~LList() value=" << value << std::endl;
    }
    int value;
    List *next;
};

TEST_RESULT test() {
  __SCOPE_LOG__;
  List * head = new List(0);
  List * temp = head;
  for (int i = 1; i <= 10; ++i) {
    temp->next = new List(i);
    temp = temp->next;
  }
  //temporary
  List *listptr, *nextptr;
  for (listptr = head; listptr != 0; listptr = nextptr) {
    nextptr = listptr->next;
    delete (listptr);
  }
  head = 0;
  RETURN_OK();
}
}  // namespace free_linkedlist

#endif //  _FREE_LINKED_LIST_H_
