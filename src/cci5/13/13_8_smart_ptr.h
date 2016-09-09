/*
 * 13_8_smart_ptr.h
 *
 *  Created on: 05 ���. 2015 �.
 *      Author: andy
 */

#ifndef _SMART_PTR_H_
#define _SMART_PTR_H_

namespace smart_ptr {

template<class T>
class SmartPointer {
 public:
  SmartPointer(T * ptr) {
    ref = ptr;
    ref_count = (unsigned*) malloc(sizeof(unsigned));
    *ref_count = 1;
  }
  SmartPointer(SmartPointer<T> & sptr) {
    ref = sptr.ref;
    ref_count = sptr.ref_count;
    ++(*ref_count);
  }
  /* Override the equal operator, so that when you set one smart
   * pointer equal to another the old smart pointer has its
   * reference count decremented and the new smart pointer has its
   * reference count incremented. */
  SmartPointer<T> & operator=(SmartPointer<T> & sptr) {
    if (this == &sptr)
      return *this;
    /* If already assigned to an object, remove one reference. */
    if (*ref_count > 0) {
      remove();
    }

    ref = sptr.ref;
    ref_count = sptr.ref_count;
    ++(*ref_count);
    return *this;
  }

  ~SmartPointer() {
    remove();  // Remove one reference to object.
  }

  T getValue() {
    return *ref;
  }

 protected:
  void remove() {
    --(*ref_count);
    if (*ref_count == 0) {
      delete ref;
      free(ref_count);
      ref = 0;
      ref_count = 0;
    }
  }

  T * ref;
  unsigned * ref_count;
};

TEST_RESULT test() {
  __SCOPE_LOG__;
  RETURN_OK();
}

}  // smart_ptr

#endif /* _SMART_PTR_H_ */
