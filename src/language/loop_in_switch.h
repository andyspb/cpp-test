#ifndef _LOOP_IN_SWITCH_H_
#define _LOOP_IN_SWITCH_H_

#include <iostream>

namespace loop_in_switch {

int test_for_in_switch(void) {
  static int i, state = 0;
  switch (state) {
    case 0: /* start of function */
      for (i = 0; i < 10; i++) {
        state = 1; /* so we will come back to "case 1" */
        return i;
        case 1:; /* resume control straight after the return */
      }
      break;
  }
  return 0;
}

void test_loop_in_switch() {
  int count = 14;
  int n = (count + 7) / 8; /* count > 0 assumed */
  std::cout << "n=" << n << std::endl;
  std::cout << "count % 8=" << count % 8 << std::endl;
  switch (count % 8) {
    do {
      case 7:
        std::cout << n << ":7" << std::endl;
      case 6:
        std::cout << n << ":6" << std::endl;
    } while (--n > 0);
  case 5:
    std::cout << n << ":5" << std::endl;
    break;
  case 4:
    std::cout << n << ":4" << std::endl;
    break;
  case 3:
    std::cout << n << ":3" << std::endl;
    break;
  case 2:
    std::cout << n << ":2" << std::endl;
    break;
  case 1:
    std::cout << n << ":1" << std::endl;
    break;
  case 0:
    std::cout << n << ":0" << std::endl;
    break;
  }
  return;
}

void test_goto_in_for() {
  int i = 0;
  goto start;
  for (; i < 10; ++i) {
    std::cout << ", ";
    start: std::cout << i;
  }
}

int test() {
  std::cout << "Test: loops and goto within a switch" << std::endl;
  std::cout << test_for_in_switch() << std::endl;
  test_loop_in_switch() ;
  test_goto_in_for();
  return 1;
}

} // namespace loop_in_switch

#endif // _LOOP_IN_SWITCH_H_
