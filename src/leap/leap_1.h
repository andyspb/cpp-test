/*
 * test_1.h
 *
 *  Created on: 23 дек. 2016 г.
 *      Author: andy
 */

#ifndef SRC_LEAP_LEAP_1_H_
#define SRC_LEAP_LEAP_1_H_

#include <iostream>

namespace _leap_1 {
// Linked list
class L {
 public:
  L(int v): value(v), next(0) {}
  L(int v, L* n): value(v), next(n) {}
  int value;
  L* next;
};

// write a function to return Nth item from tail?
L* get_nth_tail(L* head, int n) {
  __SCOPE_LOG__;
  if (!head && n < 0)
    return 0;

  L* t(head);
  int counter = 0;
  while (head && t) {
    if (++counter > n) {
      LOG(INFO) << "counter=" << counter << " n=" << n
          << " head->value=" <<head->value << std::endl;
      head = head->next;
    }
    LOG(INFO) << " t->value=" <<t->value << std::endl;
    t = t->next;
  }

  if (counter < n)
    return 0;
  else
    return head;
}

TEST_RESULT test() {
  __SCOPE_LOG__;

  L l10(10);
  L l9(9, &l10);
  L l8(8, &l9);
  L l7(7, &l8);
  L l6(6, &l7);
  L l5(5, &l6);
  L l4(4, &l5);
  L l3(3, &l4);
  L l2(2, &l3);
  L l1(1, &l2);


  L* l = get_nth_tail(&l1, 5);

  std::cout << "l=" << l->value << std::endl;
  RETURN_OK();
}

}  // namespace test_1

#endif /* SRC_LEAP_LEAP_1_H_ */
