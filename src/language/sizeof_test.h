#include <iostream>
#include <cassert>

namespace size_of_test {

struct aClass {
};

void AssertMemoryTest() {
  std::cout << "AsserMemoryTest" << std::endl;
  errno = -1;
  std::cout << "errno = " << errno << std::endl;

  aClass * ptr_a = NULL;

  ptr_a = new aClass();

  assert(ptr_a);

  delete (ptr_a);

  std::cout << "Global variable test" << std::endl;

  extern int my_global_int;
  std::cout << "my_global_int:" << my_global_int << std::endl;

  extern float my_global_float;
  std::cout << "my_global_float:" << my_global_float << std::endl;

  //extern int my_global_static_int;
  //cout<<"my_global_static_int:"<<my_global_static_int<<endl;

  //extern int static_int;
  //cout<<"static_int:"<<static_int<<endl;

  std::cout << "sizeof(double)=" << sizeof(double) << std::endl;
  std::cout << "sizeof(float)=" << sizeof(float) << std::endl;
  std::cout << "sizeof(long long)=" << sizeof(long long) << std::endl;
}

}  // namespace size_of_test

