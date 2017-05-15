/*
 * common.h
 *
 *  Created on: May 14, 2017
 *      Author: andy
 */

#ifndef SRC_CPP1X_COMMON_H_
#define SRC_CPP1X_COMMON_H_

#include <iostream>
#include <vector>

typedef std::vector<int>::iterator iterator;


// Forward declaration
void print_vector(const std::vector<int>&);

template<typename T = int>
void print_vector(const std::vector<T>& v);

template<typename T = int>
void print_vector_it(const std::vector<T>& v);




// Implementation
void print_vector(const std::vector<int>& vec) {
  for (const auto& v: vec)  {
    std::cout << v << " ";
  }
  std::cout<<std::endl;
}

template<typename T = int>
void print_vector(const std::vector<T>& v) {
  for (auto elem : v) {
    std::cout << elem << " ";
  }
  std::endl(std::cout);
}

template<typename T = int>
void print_vector_it(const std::vector<T>& v) {
  std::copy(v.begin(), v.end(), std::ostream_iterator<T>(std::cout, " "));
  std::endl(std::cout);
}




#endif /* SRC_CPP1X_COMMON_H_ */
