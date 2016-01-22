/*
 * test_antipattern.h
 *
 *  Created on: Jan 15, 2016
 *      Author: andy
 */

#ifndef SRC_LGE_ANTIPATTERN_H_
#define SRC_LGE_ANTIPATTERN_H_

#include <stdio.h>

namespace anti_pattern {
class Base{
public:
  int* pointer_to_data_;
};

class Derived: public Base {
 public:
  Derived() {
    data_ = 10;
    pointer_to_data_=&data_;
  }
 private:
  int data_;
};

TEST_RESULT test() {
  Derived d;
  *d.pointer_to_data_ = 20;
  printf("%d\n", *d.pointer_to_data_);

  RETURN_OK();
}

}  // namespace anti_pattern

#endif /* SRC_LGE_ANTIPATTERN_H_ */
