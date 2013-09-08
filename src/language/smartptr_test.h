#include  "trace.h"
namespace smartptr_test {
template<class T>
class SmartPtr {
  public:
    explicit SmartPtr(T* pointee)
        : pointee_(pointee) {
      trace("SmartPtr >>> constructor\n");
    }
    ;
    SmartPtr& operator=(const SmartPtr& other) {
      pointee_ = other;
      return *this;
    }
    ~SmartPtr() {
      delete pointee_;
      trace("destructor<<< SmartPtr \n");
    }
    T& operator*() const {
      return *pointee_;
    }
    T* operator->() const {
      return pointee_;
    }
  private:
    T* pointee_;
};

class A {

};
void test(void) {
  SmartPtr<A> ptr(new A);
}

}
