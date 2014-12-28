#ifndef MEM_TEST_H
#define MEM_TEST_H

#include <stdio.h>

namespace mem_test {

class A {
  public:
    A() { printf("%s\n", "from constructor A()");}
    ~A() { printf("%s\n", "from destructor ~A()");}
};

int test() {
   {
        A a;
        goto out;
#pragma GCC diagnostic ignored "-Wunused-variable"
        int i = 0;
    }
out:
    return 1;
}

}

#endif // MEM_TEST_H
