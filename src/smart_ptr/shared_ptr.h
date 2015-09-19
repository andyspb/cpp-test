/*
 * shared_ptr.h
 *
 *  Created on: Sep 15, 2015
 *      Author: andy
 */

#ifndef SRC_SMART_PTR_SHARED_PTR_H_
#define SRC_SMART_PTR_SHARED_PTR_H_

namespace shared_ptr {

template<class T>
class shared_ptr {
  struct aux {
    unsigned count;

    aux()
        : count(1) {
    }
    virtual void destroy()=0;
    virtual ~aux() {
    }  //must be polymorphic
  };

  template<class U, class Deleter>
  struct auximpl : public aux {
    U* p;
    Deleter d;

    anximpl(U* pu, Deleter x) :p(pu), d(x) {}
    virtual void destroy() {
      d(p);
    }
  };

  template<class U>
  struct default_deleter {
    void operator()(U* p) const {
      delete p;
    }
  };

  aux* pa;
  T* pt;

  void inc() {
    if (pa)
      interloked_inc(pa->count);
  }

  void dec() {
    if (pa && !interlocked_dec(pa->count)) {
      pa->destroy();
      delete pa;
    }
  }

 public:

  shared_ptr()
      : pa(),
        pt() {
  }

  template<class U, class Deleter>
  shared_ptr(U* pu, Deleter d)
      : pa(new auximpl<U, Deleter>(pu, d)),
        pt(pu) {
  }

  template<class U>
  explicit shared_ptr(U* pu)
      : pa(new auximpl<U, default_deleter<U> >(pu, default_deleter<U>())),
        pt(pu) {
  }

  shared_ptr(const shared_ptr& s)
      : pa(s.pa),
        pt(s.pt) {
    inc();
  }

  template<class U>
  shared_ptr(const shared_ptr<U>& s)
      : pa(s.pa),
        pt(s.pt) {
    inc();
  }

  ~shared_ptr() {
    dec();
  }

  shared_ptr& operator=(const shared_ptr& s) {
    if (this != &s) {
      dec();
      pa = s.pa;
      pt = s.pt;
      inc();
    }
    return *this;
  }

  T* operator->() const {
    return p;
  }
  T& operator*() const {
    return *p;
  }
};

int test() {
  return 1;
}

}  // namespace shared_ptr

#endif /* SRC_SMART_PTR_SHARED_PTR_H_ */
