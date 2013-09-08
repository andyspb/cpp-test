#pragma once
#include "stdafx.h"
namespace raii {

class file {
  public:
#pragma warning(disable:4996)
    file(const char* filename)
        : file_(std::fopen(filename, "a+")) {
      if (!file_) {
        throw std::runtime_error("file open failure");
      }
    }

    ~file() {
      if (std::fclose(file_)) {
        // failed to flush latest changes.
        // handle it
      }
    }

    void write(const char* str) {
      if (EOF == std::fputs(str, file_)) {
        throw std::runtime_error("file write failure");
      }
    }

  private:
    std::FILE* file_;

    // prevent copying and assignment; not implemented
    file(const file &);
    file & operator=(const file &);

};

//The class file can then be used as follows:
void test() {
  printf("RAII pattern test\n");
  file logfile("logfile.txt"); // open file (acquire resource)
  logfile.write("hello logfile!");
  // continue using logfile ...
  // throw exceptions or return without
  //  worrying about closing the log;
  // it is closed automatically when
  // logfile goes out of scope
  printf("\n");
}

}
