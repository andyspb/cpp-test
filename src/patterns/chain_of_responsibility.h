#ifndef _CHAIN_OF_RESPONSIBILITY_H_
#define _CHAIN_OF_RESPONSIBILITY_H_

#include <iostream>

namespace chain_of_responsibility {

class Output {
  public:
    void output(const std::string & str) {
      std::cout << str << std::endl;
    }
};

class World {
    Output & out;
  public:
    World(Output & out)
        : out(out) {
    }
    void output(const std::string & str) {
      out.output(str + " (output from word)world!");
    }
};

class Hello {
    World & world;
  public:
    Hello(World & world)
        : world(world) {
    }
    void output() {
      world.output("(Output from hello)Hello");
    }
};

void hello_world(Hello & hello) {
  hello.output();
}

int test() {
  std::cout << "Test: Chain_of_responsibility pattern example --->" << std::endl;
  Output output;
  World world(output);
  Hello hello(world);
  hello_world(hello);
  std::cout << "<--- test passed " << std::endl;
  return 1;
}

} // namespace chain_of_responsibility

#endif // _CHAIN_OF_RESPONSIBILITY_H_
