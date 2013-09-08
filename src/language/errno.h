#include <errno.h>

void testErrno1(void) {
  errno = ENOENT;
}

void testErrno2(void) {
  errno = ENOMEM;
}
