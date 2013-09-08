#ifndef _MEMENTO_H
#define _MEMENTO_H

#include <iostream>

namespace memento {

class Memento {
  public:
    Memento(std::string & str, const std::string newString)
        : oldString(str) {
      str = newString;
    }
    void undo(std::string & str) {
      str = oldString;
    }

  private:
    std::string oldString;
};

void hello_world(Memento & memento) {
  std::string message;
  memento.undo(message);
  std::cout << message << std::endl;
}

int test() {
  std::cout << "Memento pattern test" << "\n";
  std::string hw("Old value!");
  Memento mem(hw, "New value!");
  hello_world(mem);
  std::cout << "<--- test passed" << std::endl;
  return 1;
}
} // namespace memento

#endif // _MEMENTO_H
