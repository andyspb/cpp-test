/*
 * fast_cin.h
 *
 *  Created on: Apr 24, 2017
 *      Author: andy
 */

#ifndef SRC_FAST_IO_FAST_CIN_H_
#define SRC_FAST_IO_FAST_CIN_H_

#include <bits/stdc++.h>

namespace fast_cin {

TEST_RESULT test() {
  __SCOPE_LOG__;

  // added the two lines below
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n, k, t;
  int cnt = 0;
  std::cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    std::cin >> t;
    if (t % k == 0)
      ++cnt;
  }
  std::cout << cnt << "\n";
  return 0;

  RETURN_OK();
}

}  // namespace fast_cin

#endif /* SRC_FAST_IO_FAST_CIN_H_ */
