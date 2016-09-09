/*
 * linear_search.h
 *
 *  Created on: Jul 10, 2016
 *      Author: andy
 */

#ifndef SRC_ALGORITMS_LINEAR_SEARCH_H_
#define SRC_ALGORITMS_LINEAR_SEARCH_H_

namespace linear_search {

TEST_RESULT test() {
  __SCOPE_LOG__;
#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic push
#endif
  int arr[] = {1,2,3,5,6,7,8,9,11,22,33,44,55};
  RETURN_OK();
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif
}

}  // namespace linear_search



#endif /* SRC_ALGORITMS_LINEAR_SEARCH_H_ */
