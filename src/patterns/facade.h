#ifndef _FACADE_H_
#define _FACADE_H_

#include <iostream>

namespace facade {
class CPU {
  public:
    void freeze() {
      std::cout << "CPU freezes" << std::endl;
    }
    void jump(long position) {
      std::cout << "CPU jump to " << position << std::endl;
    }
    void execute() {
      std::cout << "CPU executes" << std::endl;
    }
};

class Memory {
  public:
    void load(long position, int[]) {
      std::cout << "Memory load "<< position << std::endl;
    }
};

class HardDrive {
  public:
    int* read(long lba, int size) {
      std::cout << "Hardware read " << lba << "lba " << size << "size" << std::endl;
      return 0;
    }
};

/* Facade */
class Computer {
  public:
    Computer() {
      this->cpu = new CPU();
      this->memory = new Memory();
      this->hardDrive = new HardDrive();
    }
    void startComputer() {
      cpu->freeze();
      memory->load(10000, hardDrive->read(55555, 45));
      cpu->jump(55555);
      cpu->execute();
    }
  private:
    CPU * cpu;
    Memory * memory;
    HardDrive * hardDrive;
};

/* Client */
int test() {
  std::cout << "Test: Facade pattern example --->" << std::endl;
  Computer facade;
  facade.startComputer();
  std::cout << "<--- test passed" << std::endl;
  return 1;
}
}  // namespace fasade

#endif // _FACADE_H_
