/*
 * moto.h
 *
 *  Created on: 15 ���. 2015 �.
 *      Author: andy
 */
#ifndef MOTO_H_
#define MOTO_H_

#include <iostream>
#include <fstream>
#include <string>
#include <queue>

//Write an algorithm to implement git diff (Only text files diff)
//git diff algorithm

std::string git_diff(std::fstream& f1, std::fstream& f2) {
  if (!f1.good() || !f2.good())
    throw("SOme file incorrect");

  std::string output;
  std::string out1;
  std::string out2;
  std::queue<std::string> q1;
  std::queue<std::string> q2;

  std::string s1;
  std::string s2;

  bool endBlock = false;

  while (f1.good()) {
    std::getline(f1, s1);
    q1.push(s1 + "\n");
  }

  while (f2.good()) {
    std::getline(f2, s2);
    q2.push(s2 + "\n");
  }

  bool equal = false;
  while (!q1.empty() && !q2.empty()) {
    out1 = q1.front();
    out2 = q2.front();
    while (!equal) {
    }
//    else {
//      std::cout << "s1 == s2" << std::endl;
//      while (!q1.empty() ) {
//        std::cout << "!q1.empty()" << std::endl;
//        output.append(" --- " + q1.front());
//        q1.pop();
//      }
//      while (!q2.empty()) {
//        std::cout << "!q1.empty()" << std::endl;
//        output.append(" +++ " + q2.front());
//        q2.pop();
//      }
//    }
  }
//  while (!q1.empty() ) {
//    std::cout << "!q1.empty()" << std::endl;
//    output.append(" --- " + q1.front());
//    q1.pop();
//  }
//  while (!q2.empty()) {
//    std::cout << "!q1.empty()" << std::endl;
//    output.append(" +++ " + q2.front());
//    q2.pop();
//  }

  return output;

}

// 2. write function, to check whether there are two adjacent bits are 1, given a 32 bits integer
bool adj11(int n) {
  if (std::abs(n < 3))
    return false;
  while (n > 0) {
    if ((n & 3) > 0)
      return true;
    n = n >> 1;
  }
  return false;
}

namespace moto {

int test() {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
  std::fstream f1("d:\\test1.txt", std::fstream::in | std::fstream::out);
  std::fstream f2("d:\\test2.txt", std::fstream::in | std::fstream::out);

  std::string s = git_diff(f1, f2);

  std::cout << "output:\n" << s << std::endl;

  f1.close();
  f1.close();

  return 1;
}

}  // namespace moto

#endif /* MOTO_H_ */
