#ifndef _VIRT_PRIVATE_ACCESS_H_
#define _VIRT_PRIVATE_ACCESS_H_
// vitual_method_with_private_access.h

namespace virt_private_access {
class B {
  public:
    virtual ~B() {
    }
    virtual void f() {
    }
};

class D: public B {
  public:
    virtual ~D() {
    }
//private:
    void f() {
    }
};

int test() {
  std::cout << "Test: Private access to virtual function" << std::endl;

  D dobj;
  B* bptr = &dobj;
  D* dptr = &dobj;
  // valid, virtual B::f() is public,
  // D::f() is called
  bptr->f();
  // error, D::f() is private
  dptr->f();
  std::cout << "<--- test passed";
  return 1;
}
} // namespace virt_private_access

#endif /* _VIRT_PRIVATE_ACCESS_H_ */
