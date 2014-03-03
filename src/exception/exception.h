/*
 * exception.h
 *
 *  Created on: Feb 28, 2014
 *      Author: andy
 */

#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include <iostream>

namespace exception_ {

struct my_exc1 : std::exception {
  char const* what() const throw () {
    return "what my_exc1";
  }
};

struct my_exc2 : std::exception {
  char const* what() const throw () {
    return "what my_exc2";
  }
};
struct your_exc3 : my_exc1, my_exc2 {

};

int test() {
  std::cout << "exception_::test() --->\n";
  try {
    throw your_exc3();
  }
  catch (std::exception const& e) {
    std::cout << e.what();
  }
  catch (...) {
    std::cout << "whoops!" << std::endl;
  }
  std::cout << "<---\n";
  return 1;
}

}  // namespace exception_

#endif /* EXCEPTION_H_ */
