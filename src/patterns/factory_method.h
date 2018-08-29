#ifndef _FACTORY_METHOD_H_
#define _FACTORY_METHOD_H_

#include <iostream>

namespace factory_method {

class Pizza {
 public:
  virtual ~Pizza() {
  }
  virtual int getPrice() = 0;  // count the cents
};

class HamAndMushroomPizza : public Pizza {
 public:
  virtual ~HamAndMushroomPizza() {
  }
  virtual int getPrice() {
    return 850;
  }
};

class DeluxePizza : public Pizza {
 public:
  virtual ~DeluxePizza() {
  }
  virtual int getPrice() {
    return 1050;
  }
};

class HawaiianPizza : public Pizza {
 public:
  virtual ~HawaiianPizza() {
  }
  virtual int getPrice() {
    return 1150;
  }
};

class PizzaFactory {
 public:
  typedef enum {
    HamMushroom = 0,
    Deluxe = 1,
    Hawaiian = 2
  } PizzaType;

  static Pizza * createPizza(PizzaType pizzaType) {
    switch (pizzaType) {
      case HamMushroom:
        return new HamAndMushroomPizza();
      case Deluxe:
        return new DeluxePizza();
      case Hawaiian:
        return new HawaiianPizza();
      default:
        return 0;
    }
  }
};

int test() {
  std::cout << "Test: Factory pattern example --->" << std::endl;
  Pizza * pz_1 = PizzaFactory::createPizza(PizzaFactory::Deluxe);
  if (pz_1)
    printf("Price of %d is %d\n", PizzaFactory::Deluxe, pz_1->getPrice());

  Pizza * pz_2 = PizzaFactory::createPizza(PizzaFactory::HamMushroom);
  if (pz_2)
    printf("Price of %d is %d\n", PizzaFactory::HamMushroom, pz_2->getPrice());
  Pizza * pz_3 = PizzaFactory::createPizza(PizzaFactory::Hawaiian);
  if (pz_3)
    printf("Price of %d is %d\n", PizzaFactory::Hawaiian, pz_3->getPrice());
  std::cout << "<--- test passed" << std::endl;
  return 1;
}
}  // namespace factory_method

#endif // _FACTORY_METHOD_H_
