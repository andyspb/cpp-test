/*
 * test.h
 *
 *  Created on: Jun 27, 2016
 *      Author: andy
 */

#ifndef SRC_TERAMIND_TERRAMIND_1_H_
#define SRC_TERAMIND_TERRAMIND_1_H_

namespace terramind_1 {

// If a struct has some members of type int and char, how do you compare two
// instances of this struct to see if the members have the same value? *
struct A {
  int a;
  char b;
};

int CompareA(const A& a1, const A& a2) {
  long long l1 = 0;
  long long l2 = 0;
  l1 = ((long long) a1.a << 32) + a1.b;
  l2 = ((long long) a2.a << 32) + a2.b;

  if (l1 > l2)
    return 1;
  else if (l2 > l1)
    return -1;
  else
    return 0;
}

TEST_RESULT test() {
  __SCOPE_LOG__;

  RETURN_OK();
}

}  // terramind_1

#endif /* SRC_TERAMIND_TERRAMIND_1_H_ */
