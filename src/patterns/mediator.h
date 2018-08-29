#ifndef _MEDIATOR_H_
#define _MEDIATOR_H_

#include <iostream>
namespace mediator {

class Printer {
 public:
  virtual ~Printer() {
  }
  void print(const std::string & str) const {
    std::cout << str << std::endl;
  }
};

class Message {
 public:
  virtual ~Message() {
  }
  virtual void print(const class Mediator & mediator) const;
};

class Mediator {
  const Printer & printer;
  const Message & message;
 public:
  Mediator(const Printer & pr, const Message & msg)
      : printer(pr),
        message(msg) {
  }
  virtual ~Mediator() {
  }
  void print() const {
    message.print(*this);
  }
  void print(const std::string & str) const {
    printer.print(str);
  }
};

inline void Message::print(const Mediator & mediator) const {
  mediator.print("Hello world!");
}

void hello_world(const Mediator & mediator) {
  mediator.print();
}

int test() {
  std::cout << "Test: Mediator pattern example --->" << std::endl;
  Printer printer;
  Message message;
  hello_world(Mediator(printer, message));
  std::cout << "<--- test passed" << std::endl;
  return 1;
}
}  // namespace mediator

#endif // _MEDIATOR_H_
