#pragma once
#include "stdafx.h"

namespace null_object {

class Recipient {
 public:
  virtual ~Recipient() {
  }
  virtual std::string name() const=0;
};

class NullRecipient : public Recipient {
 public:
  std::string name() const {
    return "nobody";
  }
};

class _World : public Recipient {
 public:
  std::string name() const {
    return "world";
  }
};

void test_real(const Recipient & recipient = _World()) {
  std::cout << "Hello " << recipient.name() << "!" << std::endl;
}

void test_null(const Recipient & recipient = NullRecipient()) {
  std::cout << "Hello " << recipient.name() << "!" << std::endl;
}

int test() {
  printf("Null_object pattern test\n");
  test_real(_World());
  test_null();
  printf("\n");
  return 0;
}

}
