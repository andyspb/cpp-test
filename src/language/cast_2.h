//What is the difference between static_cast and dynamic_cast?
//Show examples of where they can be used? Show how dynamic_cast can be used to test down-casting
#ifndef _CAST_2_H_
#define _CAST_2_H_

#include <iostream>
#include <list>

namespace cast_2 {
class Base {
  public:
    virtual void funcB()=0;
    virtual ~Base() {
       std::cout << "From Base::~Base()" <<std::endl;
    }
};

class Derived: public Base {
  public:
    virtual ~Derived() {
    }
    virtual void funcB() {
      std::cout << "D::funcB" << std::endl;
    }
    void func() {
      std::cout << "D::func" << std::endl;
    }
};

void test_1() {

  std::cout << "test_1" << std::endl;

  Derived* pD = new Derived;
  std::list<Base*> b;
  b.push_back(pD);
  for (std::list<Base*>::iterator p = b.begin(); p != b.end(); ++p) {
    static_cast<Derived*>(*p)->funcB();
    dynamic_cast<Derived*>(*p)->funcB();
  }
  std::endl(std::cout);
}

class Pet {
  public:
    virtual ~Pet() {
    }
};
class Dog: public Pet {
};
class Cat: public Pet {
};

void test_2() {
//  std::cout << sizeof(long) << std::endl;

  Pet* pet_ptr = new Cat; // Upcast
  // Try to cast it to Dog*:
  Dog* dog_ptr = dynamic_cast<Dog*>(pet_ptr);
  // Try to cast it to Cat*:
  Cat* cat_ptr = dynamic_cast<Cat*>(pet_ptr);

  std::cout << "pet_ptr: " << pet_ptr << std::endl;
  std::cout << "dog_ptr: " << dog_ptr << std::endl;
  std::cout << "cat_ptr: " << cat_ptr << std::endl;
}

int test() {
  std::cout << "Test: cast_2 --->" << std::endl;
  test_1();
  test_2();

//	void * v = malloc(sizeof(int));
//	void * v1 = calloc(10, sizeof(int));
  return 1;
}
} //namespace cast_2

#endif  // _CAST_2_H_
