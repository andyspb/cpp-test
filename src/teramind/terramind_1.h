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
struct IntChar {
  IntChar(int i, char c) {
    int_ = i;
    char_ = c;
  }

  int int_;
  char char_;
};

int CompareIntCharStruct(const IntChar& a1, const IntChar& a2) {
  long long l1 = 0;
  long long l2 = 0;
  l1 = ((long long) a1.int_ << 32) + a1.char_;
  l2 = ((long long) a2.int_ << 32) + a2.char_;

  if (l1 > l2)
    return 1;
  else if (l2 > l1)
    return -1;
  else
    return 0;
}

TEST_RESULT test() {
  __SCOPE_LOG__;

  IntChar ic1(22, 33);
  IntChar ic2(23, 34);
  IntChar ic3(22, 33);

  int comp1 = CompareIntCharStruct(ic1, ic2);
  int comp2 = CompareIntCharStruct(ic2, ic3);
  int comp3 = CompareIntCharStruct(ic1, ic3);

  LOG(INFO) << "comp1=" << comp1;
  LOG(INFO) << "comp2=" << comp2;
  LOG(INFO) << "comp3=" << comp3;

  RETURN_OK();
}

}  // terramind_1

#endif /* SRC_TERAMIND_TERRAMIND_1_H_ */
