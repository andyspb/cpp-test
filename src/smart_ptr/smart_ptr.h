//  smart_ptr.h
//  author: andrey.krutogolov@gmail.com
//  date:   12.03.2013

#ifndef SMART_PTR_H_
#define SMART_PTR_H_

#include <iostream>
#include <memory>

namespace smart_ptr {

std::weak_ptr<int> gw;

void f() {
  if (auto spt = gw.lock()) {  // Has to be copied into a shared_ptr before usage
    std::cout << *spt << "\n";
  } else {
    std::cout << "gw is expired\n";
  }
}
int test() {

  {
    auto sp = std::make_shared<int>(42);
    gw = sp;

    f();
  }

  f();
  return 1;
}

}  // namespace smart_ptr

#endif  // SMART_PTR_H_
