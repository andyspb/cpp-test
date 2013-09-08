//  tests12.h
//  author: andrey.krutogolov@gmail.com
//  date:   23.03.2013


#ifndef TESTS12_H_
#define TESTS12_H_

#include <iostream>

namespace tests12 {

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

int main() {

  int i = 5;
  std::cout << i << std::endl;
  std::cout << sizeof(++i) << std::endl;
  std::cout << i << std::endl;

//  Player p;
  return 0;
}

}  // namespace tests12



#endif  // TESTS12_H_
