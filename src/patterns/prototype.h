#ifndef _PROTOTYPE_H_
#define _PROTOTYPE_H_

#include <iostream>
namespace prototype {
class PrototypeFactory {
 public:
  virtual ~PrototypeFactory() {
  }
  virtual PrototypeFactory * clone() {
    PrototypeFactory * copy = new PrototypeFactory();
    //In an actual implementation of this pattern you might now change references to
    //the expensive to produce parts from the copies that are held inside the prototype.
    return copy;
  }
  virtual void prototypeFactory(int x) {
  }
  virtual void printValue() {
  }
};

/**
 * Concrete Prototypes to clone
 */
class PrototypeImpl : public PrototypeFactory {
 public:
  virtual ~PrototypeImpl() {
  }
  PrototypeImpl(int x) {
    this->x = x;
  }
  void prototypeFactory(int x) {
    this->x = x;
  }
  void printValue() {
    printf("Value :%d\n", x);
  }
 private:
  int x;
};

/**
 * Client Class
 */
class PrototypeExample {
 public:
  PrototypeExample(PrototypeFactory * example) {
    this->example = example;
  }
  PrototypeFactory * makeCopy() {
    return (PrototypeFactory *) this->example->clone();
  }

 private:
  PrototypeFactory * example;  // Could have been a private Cloneable example.
};

int test() {
  std::cout << "Test: Prototype pattern example --->" << std::endl;
  PrototypeFactory * tempExample = 0;
  int num = 1000;
  PrototypeFactory * prot = new PrototypeImpl(1000);
  PrototypeExample * cm = new PrototypeExample(prot);
  for (int i = 0; i < 10; i++) {
    tempExample = cm->makeCopy();
    tempExample->prototypeFactory(i * num);
    tempExample->printValue();
  }
  std::cout << "<--- test passed" << std::endl;
  return 1;
}
}  // namespace prototype

#endif // _OBSERVER_H_
