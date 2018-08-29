#ifndef _ABSTRACT_FACTORY_H_
#define _ABSTRACT_FACTORY_H_

#include <iostream>

namespace abstract_factory {
class Button {
 public:
  virtual ~Button() {
  }
  virtual void paint() = 0;
};

class WinButton : public Button {
 public:
  virtual ~WinButton() {
  }
  virtual void paint() {
    std::cout << "\tpaint(): I'm a WinButton\n";
  }
};

class OSXButton : public Button {
 public:
  virtual void paint() {
    std::cout << "paint(): I'm an OSXButton\n";
  }
};

class GUIFactory {
 public:
  virtual ~GUIFactory() {
  }
  virtual Button * createButton() = 0;
};

class WinFactory : public GUIFactory {
 public:
  virtual ~WinFactory() {
  }
  virtual Button * createButton() {
    return new WinButton();
  }
};

class OSXFactory : public GUIFactory {
 public:
  virtual ~OSXFactory() {
  }
  virtual Button * createButton() {
    return new OSXButton();
  }
};

class Application {
 public:
  Application(GUIFactory * factory) {
    Button * button = factory->createButton();
    button->paint();
  }
};

GUIFactory * createOsSpecificFactory(int sys) {
  if (sys == 0) {
    return new WinFactory();
  } else {
    return new OSXFactory();
  }
}
;

int test() {
  std::cout << "Test: abstract factory --->" << std::endl;
  GUIFactory * factory = createOsSpecificFactory(0);
  Application * example = new Application(factory);
  delete (example);
  delete (factory);
  std::cout << "<--- passed" << std::endl;
  return 1;
}

}  // namespace abstract_factory

#endif //  _ABSTRACT_FACTORY_H_
