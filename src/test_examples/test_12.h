//  tests12.h
//  author: andrey.krutogolov@gmail.com
//  date:   23.03.2013


#ifndef TESTS12_H_
#define TESTS12_H_

#include <iostream>

namespace test_12 {

class Layer {
};
class Cell {
};

class Player
{
private:
    long balance;
//    Layer &current_layer;
//    Cell &current_cell;
};

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;

  int i = 5;
  std::cout << i << std::endl;
  std::cout << sizeof(++i) << std::endl;
  std::cout << i << std::endl;

//  Player p;
  RETURN_OK();
}

}  // namespace tests12



#endif  // TESTS12_H_
