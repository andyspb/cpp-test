#ifndef _BUILDER_H_
#define _BUILDER_H_

#include <iostream>
#include <string>

namespace builder {

class Pizza {
 public:
  virtual ~Pizza() {
  }

  virtual void setDough(const std::string& dough) {
    this->dough = dough;
  }

  virtual void setSauce(const std::string& sauce) {
    this->sauce = sauce;
  }

  virtual void setTopping(const std::string& topping) {
    this->topping = topping;
  }

 private:
  std::string dough;
  std::string sauce;
  std::string topping;
};

/** "Abstract Builder" */
class PizzaBuilder {
 public:
  virtual ~PizzaBuilder() {
  }

  virtual Pizza * getPizza() {
    return pizza;
  }

  virtual void createNewPizzaProduct() {
    pizza = new Pizza();
  }

  virtual void buildDough() {
  }
  virtual void buildSauce() {
  }
  virtual void buildTopping() {
  }

 protected:
  Pizza * pizza;
};

/** "ConcreteBuilder" */
class HawaiianPizzaBuilder : public PizzaBuilder {
 public:
  void buildDough() {
    pizza->setDough("cross");
  }
  void buildSauce() {
    pizza->setSauce("mild");
  }
  void buildTopping() {
    pizza->setTopping("ham+pineapple");
  }
};

/** "ConcreteBuilder" */
class SpicyPizzaBuilder : public PizzaBuilder {
 public:
  void buildDough() {
    pizza->setDough("pan baked");
  }

  void buildSauce() {
    pizza->setSauce("hot");
  }

  void buildTopping() {
    pizza->setTopping("pepperoni+salami");
  }
};

/** "Director" */
class Cook {
 public:
  void setPizzaBuilder(PizzaBuilder * pb) {
    pizzaBuilder = pb;
  }

  Pizza * getPizza() {
    return pizzaBuilder->getPizza();
  }

  void constructPizza() {
    pizzaBuilder->createNewPizzaProduct();
    pizzaBuilder->buildDough();
    pizzaBuilder->buildSauce();
    pizzaBuilder->buildTopping();
  }

 private:
  PizzaBuilder * pizzaBuilder;
};

/** A given type of pizza being constructed. */
int test() {
  std::cout << "Test: Builder pattern example --->" << std::endl;
  Cook * cook = new Cook();
  PizzaBuilder * hawaiianPizzaBuilder = new HawaiianPizzaBuilder();
  PizzaBuilder * spicyPizzaBuilder = new SpicyPizzaBuilder();

  cook->setPizzaBuilder(hawaiianPizzaBuilder);
  cook->constructPizza();

  Pizza * hawaiian = cook->getPizza();

  cook->setPizzaBuilder(spicyPizzaBuilder);
  cook->constructPizza();

  Pizza * spicy = cook->getPizza();
  delete (spicy);
  delete (hawaiian);
  delete (spicyPizzaBuilder);
  delete (hawaiianPizzaBuilder);
  delete (cook);
  std::cout << "<--- test passed" << std::endl;
  return 1;
}
}  // namespace builder

#endif // _BUILDER_H_
