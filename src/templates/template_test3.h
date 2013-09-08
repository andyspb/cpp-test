#ifndef _TEMPLATE_TEST3_H__
#define _TEMPLATE_TEST3_H__

#include <iostream>
#include <typeinfo>
#include <iostream>

namespace template_test3 {
template<class T>
class steal_it;

template<typename U, template<typename > class C>
struct steal_it<C<U> > {
    typedef U result_t;
};

template<typename T>
class foo {
};

template<typename T>
void test_it(T) {
  typename steal_it<T>::result_t bar = 42;
  std::cout << "\t" << typeid(bar).name() << std::endl;
}

int test() {
  std::cout << "Test templ test --->" << std::endl;
  test_it(foo<int>());
  std::cout << "<--- templ test passed" << std::endl;
  return 1;
}
}  // namespace template_test3

#endif // _TEMPLATE_TEST3_H__
