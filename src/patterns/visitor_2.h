#pragma once
#include "stdafx.h"
namespace visitor_2 {
struct PrintChar {
  void operator()(char ch) {
    std::cout << "_" << ch;
  }
};

template<typename Visitor>
void visitor_test(Visitor & visitor) {
  std::string hw("visitor_test!\n");
  std::for_each(hw.begin(), hw.end(), visitor);
}

int test() {
  printf("visitor pattern test 2\n");
  PrintChar print_char;
  visitor_test(print_char);
  printf("\n");
  return 0;
}
}
