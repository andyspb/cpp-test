#include <limits>
using namespace std;

namespace foo_test {

bool foo(double a) {
  return ((a + 1) == a);
}

void test() {
  printf("foo returns %d\n", (int) foo(numeric_limits<double>::infinity()));

  printf("foo returns %d\n", (int) foo(HUGE_VAL));

}

}  // namespace foo_test

