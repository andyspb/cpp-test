/*
 * template_default_param.h
 *
 *  Created on: May 2, 2016
 *      Author: andy
 */

#ifndef SRC_TEMPLATES_TEMPLATE_DEFAULT_PARAM_H_
#define SRC_TEMPLATES_TEMPLATE_DEFAULT_PARAM_H_

namespace template_default_param {

//template<class T = char, class U, class V = int> class A { // error
//};

template<class T, class U, class V = int> class A {

};
TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;

  RETURN_OK();
}

}  // namespace template_default_param

#endif /* SRC_TEMPLATES_TEMPLATE_DEFAULT_PARAM_H_ */
