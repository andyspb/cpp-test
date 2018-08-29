/*
 * singleton_static.h
 *
 *  Created on: 03 февр. 2015 г.
 *      Author: andy
 */

#ifndef SINGLETON_STATIC_H_
#define SINGLETON_STATIC_H_

namespace singleton_static {

class Singleton {
 public:
  static Singleton * GetInstance(void);
  void print() {
  }
  ;
 protected:
  Singleton() {
  }
  ;
  virtual ~Singleton() {
  }
  ;
 private:
  static Singleton * volatile _instance;

  Singleton(Singleton&);
  void operator=(Singleton&);

};

Singleton* volatile Singleton::_instance = new Singleton();

Singleton * Singleton::GetInstance(void) {
  return _instance;
}

int test() {
  Singleton* s = Singleton::GetInstance();
  s->print();
  return 1;
}

}  // namespace singleton_static

#endif /* SINGLETON_STATIC_H_ */
