#ifndef _STRATEGY_H_
#define _STRATEGY_H_

#include <iostream>

namespace strategy {
class StrategyInterface {
 public:
  virtual ~StrategyInterface() {
  }
  virtual void execute() const = 0;
};

class ConcreteStrategyA : public StrategyInterface {
 public:
  virtual ~ConcreteStrategyA() {
  }
  virtual void execute() const {
    std::cout << "Called ConcreteStrategyA execute method" << std::endl;
  }
};

class ConcreteStrategyB : public StrategyInterface {
 public:
  virtual ~ConcreteStrategyB() {
  }
  virtual void execute() const {
    std::cout << "Called ConcreteStrategyB execute method" << std::endl;
  }
};

class ConcreteStrategyC : public StrategyInterface {
 public:
  virtual ~ConcreteStrategyC() {
  }
  virtual void execute() const {
    std::cout << "Called ConcreteStrategyC execute method" << std::endl;
  }
};

class Context {
 private:
  StrategyInterface * strategy_;

 public:
  explicit Context(StrategyInterface *strategy)
      : strategy_(strategy) {
  }
  void set_strategy(StrategyInterface *strategy) {
    strategy_ = strategy;
  }
  void execute() const {
    strategy_->execute();
  }
};

int test() {
  std::cout << "Test: Strategy pattern example --->" << std::endl;
  ConcreteStrategyA concreteStrategyA;
  ConcreteStrategyB concreteStrategyB;
  ConcreteStrategyC concreteStrategyC;

  Context contextA(&concreteStrategyA);
  Context contextB(&concreteStrategyB);
  Context contextC(&concreteStrategyC);

  contextA.execute();  // output: "Called ConcreteStrategyA execute method"
  contextB.execute();  // output: "Called ConcreteStrategyB execute method"
  contextC.execute();  // output: "Called ConcreteStrategyC execute method"

  std::endl(std::cout);
  std::endl(std::cout);

  contextA.set_strategy(&concreteStrategyB);
  contextA.execute();  // output: "Called ConcreteStrategyB execute method"
  contextA.set_strategy(&concreteStrategyC);
  contextA.execute();  // output: "Called ConcreteStrategyC execute method"

  std::cout << "<--- test passed" << std::endl;
  return 1;
}
}  // namespace strategy

#endif  // _STRATEGY_H_
