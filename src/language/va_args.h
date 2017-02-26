/*
 * va_args.h
 *
 *  Created on: Jul 28, 2016
 *      Author: andy
 */

#ifndef SRC_LANGUAGE_VA_ARGS_H_
#define SRC_LANGUAGE_VA_ARGS_H_

#include<stdarg.h>

namespace va_args {

int maxof(int n_args, ...) {
  va_list ap;
  va_start(ap, n_args);
  int max = va_arg(ap, int);
  for (int i = 2; i <= n_args; i++) {
    int a = va_arg(ap, int);
    if (a > max)
      max = a;
  }
  va_end(ap);
  return max;
}

TEST_RESULT test() {
  __SCOPE_LOG__;
  int n = 12;
  LOG(INFO) << "n=" << n;
  int max = maxof(n, 1,3,4,5,66,7,8,999,23,666,124,1024);
  LOG(INFO) << "maxof("<< n << ", 1,3,4,5,66,7,8,999,23,666,124,1024)=" << max;
  RETURN_OK();
}

}  // namespace va_args

#endif /* SRC_LANGUAGE_VA_ARGS_H_ */
