#ifndef GOTO__H_
#define GOTO__H_

#include <stdio.h>

namespace goto_ {

int test() {
  int i = 0;
  goto A;
  for (; i < 3; ++i)
    L: {
      {
        int x;
        x += i;
        if (0) {
          A: x = 0;
          goto B;
        }
        printf("X: %d ", x);
      }
      {
        int y;
        y -= i;
        if (0) {
          B: y = 10;
          goto L;
        }
        printf("Y: %d\n", y);
      }
    }
  return 1;
}
}  // namespace goto_
#endif /* GOTO__H_ */
