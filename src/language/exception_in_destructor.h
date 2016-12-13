#include <iostream>
namespace exception_in_desctructor {

struct E {
  const char* message;
  E(const char* arg)
      : message(arg) {
  }
};

void my_terminate() {
  std::cout << "Call to my_terminate" << std::endl;
  exit(0);
}
;

struct A {
  A() {
    std::cout << "In constructor of A" << std::endl;
  }
  ~A() {
    std::cout << "In destructor of A" << std::endl;
    throw E("Exception thrown in ~A()");
  }
};

struct B {
  B() {
    std::cout << "In constructor of B" << std::endl;
  }
  ~B() {
    std::cout << "In destructor of B" << std::endl;
  }
};

void test() {
  std::set_terminate(my_terminate);
  try {
    std::cout << "In try block" << std::endl;
    A a;
    B b;
    throw("Exception thrown in try block of main()");
  } catch (const char* e) {
    std::cout << "Exception: " << e << std::endl;
  } catch (...) {
    std::cout << "Some exception caught in main()" << std::endl;
  }

  std::cout << "Resume execution of main()" << std::endl;
}
}
