/*
 * template_func.h
 *
 *  Created on: Jul 14, 2015
 *      Author: andy
 */

#ifndef SRC_TEMPLATES_TEMPLATE_FUNC_H_
#define SRC_TEMPLATES_TEMPLATE_FUNC_H_

namespace template_func {

template<int R, int C>
void myFunction(double (&myArray)[R][C])
{
    myArray[0][0] = 5;
}

TEST_RESULT test() {
  RETURN_OK();
}

}  // namespace template_func



#endif /* SRC_TEMPLATES_TEMPLATE_FUNC_H_ */
