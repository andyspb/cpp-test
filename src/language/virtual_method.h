#ifndef VIRTUAL_METHOD_H_
#define VIRTUAL_METHOD_H_

#include <iostream>

namespace virtual_method {
// Interface
class Openable {
 public:
  virtual ~Openable() {
  }
  virtual void Open() = 0;
  virtual bool IsOpen() const = 0;
};

// Abstract Class
class AbstractPort : public Openable {
 public:
  virtual ~AbstractPort() {
  }
  void Open() {
    DoOpen();
  }
  bool IsOpen() const {
    return IsOpen_;
  }

 private:
  virtual void DoOpen() = 0;

  bool IsOpen_;
};

// Concrete class
class Can : public Openable {
 public:
  virtual ~Can() {
  }
  Can()
      : IsOpen_(false) {
  }

  void Open() {
    IsOpen_ = true;
  }

  bool IsOpen() const {
    return IsOpen_;
  }

 private:
  bool IsOpen_;
};
int test() {
  std::cout << "Test: virtual methods --->" << std::endl;
  Can c;
  return 1;
}

}  // namespace virtual_method

#endif /* VIRTUAL_METHOD_H_ */
