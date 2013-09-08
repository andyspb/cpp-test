#ifndef POINTER_AS_PARAM_H_
#define POINTER_AS_PARAM_H_

#include <iostream>

namespace pointer_as_param {

int g = 35;

void func(int *p) {
std::cout << "from func() p =" << p << std::endl;
p = &g;
std::cout << "from func() p =" << p << " value=" << *p << std::endl;
}

void func_ref(int ** p) {
std::cout << "from func_ref() p =" << p << std::endl;
*p = &g;
std::cout << "from func_ref() p =" << p << " value=" << *p << std::endl;
}

int test() {
std::cout << "Test: pointer as param ---> " << std::endl;
int i = 1;
int *p = &i;
std::cout << "from test() p =" << p << " value = " << *p << std::endl;
func(p);
std::cout << "from test() p =" << p << " value = " << *p << std::endl;
func_ref(&p);
std::cout << "from test() p =" << p << " value = " << *p << std::endl;
return 1;
}
}  // namespace pointer_as_param

#endif /* POINTER_AS_PARAM_H_ */
