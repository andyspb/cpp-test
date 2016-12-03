#include <iostream>

namespace revert_slist {

class Node {
 public:
  Node(int v) : value(v), next(0) {}
  int value;
  Node* next;
};

void print_nodes(Node *node);

void ms_test_revert_linked_list(int length) {
  if (length <= 1) {
    return;
  }
  Node* _node = new Node(0);
  Node * head = _node;
  for (int i = 1; i < length; i++) {
    _node->next = new Node(i);
    _node = _node->next;
  }

  _node = NULL;
  print_nodes(head);

  Node * tmp = NULL;
  Node * reverse_list = NULL;

  while (head) {

    tmp = head;
    head = head->next;

    tmp->next = reverse_list;
    reverse_list = tmp;

  }

  head = reverse_list;
  print_nodes(head);

}

void print_nodes(Node * node) {

  while (node != NULL) {
    printf("%2d ", node->value);
    node = node->next;
  }

  std::cout << '\n';
}
}  // namespace revert_slist

