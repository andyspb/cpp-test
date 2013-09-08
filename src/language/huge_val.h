#include <limits>
using namespace std;

namespace c_foo {
bool foo(float a) {
  return ((a + 1) == a);
}

int test() {
  printf("Result %d", foo(HUGE_VAL));
  return 0;
}

}  // namespace c_foo
