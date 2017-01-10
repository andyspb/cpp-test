/*
 * overrides.h
 *
 *  Created on: 6 џэт. 2017 у.
 *      Author: andy
 */

#ifndef SRC_VIRTUAL_OVERRIDES_H_
#define SRC_VIRTUAL_OVERRIDES_H_

namespace overrides {

struct A {
    virtual ~A() {};
    virtual void f(); // Error: constrained virtual function
};


TEST_RESULT test() {
  __SCOPE_LOG__;
  LOG(INFO) << __PRETTY_FUNCTION__;


  RETURN_OK();
}

}  // namespace overrides

#endif /* SRC_VIRTUAL_OVERRIDES_H_ */
