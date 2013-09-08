#include <iostream>
using namespace std;

void AssertMemoryTest() {
  cout << "AsserMemoryTest" << endl;
  errno = -1;
  cout << "errno = " << errno << endl;

  aClass * ptr_a = NULL;

  ptr_a = new aClass();

  assert(ptr_a);

  delete (ptr_a);

  cout << endl << "Global variable test" << endl;

  extern int my_global_int;
  cout << "my_global_int:" << my_global_int << endl;

  extern float my_global_float;
  cout << "my_global_float:" << my_global_float << endl;

  //extern int my_global_static_int;
  //cout<<"my_global_static_int:"<<my_global_static_int<<endl;

  //extern int static_int;
  //cout<<"static_int:"<<static_int<<endl;

  cout << "sizeof(double)=" << sizeof(double) << endl;
  cout << "sizeof(float)=" << sizeof(float) << endl;
  cout << "sizeof(long long)=" << sizeof(long long) << endl;
}
