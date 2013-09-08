#ifndef _VIRT_FUNC_1_H_
#define _VIRT_FUNC_1_H_

#include <iostream>

namespace virt_func_1 {
class Base {
  public:
    Base() {}
    virtual ~Base() {
      std::cout << "From ~Base()" << std::endl;
    }
    virtual void f() {
      std::cout << "From Base::f()" << std::endl;
    }
};

class Derived: public Base {
  private:
    ~Derived() {
      std::cout << "From ~Derived()" << std::endl;
    }
    void f() {
      std::cout << "From Derived::f()" << std::endl;
    }
};

class A {
  public:
    //void nonvirt() = 0;
    /*virtual*/
    void f(); // = 0 ;//{ cout << "Class A" << endl; }
    A() {
      std::cout << "From A::A()" << std::endl;
    }
  protected:
    ~A() {
      std::cout << "from A::~A()" << std::endl;
      delete this;
    }
};
void A::f() {
  std::cout << "From A::f()" << std::endl;
}

class B: public A {
  public:
    B() {
      std::cout << "From B::B()" << std::endl;
    }
    void f() {
      std::cout << "B::f()" << std::endl;
    }
    ~B() {
      std::cout << "From B::~B()" << std::endl;
    }
};

class C: public B {

  public:
    void f() {
      std::cout << "From C::f()" << std::endl;
    }
    virtual ~C() {
      std::cout << "From C::~C()" << std::endl;
    }
    C() {
      std::cout << "From C::C()" << std::endl;
    }

    //C(const volatile C& c )
    //{
    //	cout<<"C copy constructor"<<endl;
    //}

    //C& operator= (const volatile C& c)
    //{
    //	cout<<"C assignment operator"<<endl;
    //	return *this;
    //}

};

int test() {
  std::cout << "Test: Virtual function 1 --->" << std::endl;
  Base *pb = new Derived();
  pb->f();

  delete pb;

  //	C * a = new C();
  //a->f();

  //	delete a;

  //      C  _a;

  //A* a = new C(_a);
  //a->f();

  //C a1 = _a;

  //delete a;
  //if (!a)
  //{
  //	cout<<"!a"<<endl;
  //}
  //a = NULL;
  //if (!a)
  //{
  //	cout<<" a = NULL"<<endl;
  //}

  //char * c = new char[0];

  //B b; C c;
  //A* pa1 = &b;
  //A* pa2 = &c;
  ////   b.f();
  //pa1->f();
  //pa2->f();
  return 1;
}
} // namespace virt_func_1

#endif // _VIRT_FUNC_1_H_
