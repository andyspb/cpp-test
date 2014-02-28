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

//struct my_exc1 : virtual std::exception {
//  char const* what() const throw ();
//};
struct my_exc2 :  std::exception {
  char const* what() const throw ();
};
struct your_exc3 : my_exc2 {

};

int test() {
  try {
    throw your_exc3();
  } catch (std::exception const& e) {
  } catch (...) {
    std::cout << "whoops!" << std::endl;
  }
  return 1;
}

}  // namespace exception_

#endif /* EXCEPTION_H_ */
