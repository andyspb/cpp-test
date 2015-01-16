/*
 * moto.h
 *
 *  Created on: 15 ���. 2015 �.
 *      Author: andy
 */
#ifndef MOTO_H_
#define MOTO_H_

#include <fstream>
#include <string>
#include <queue>

//Write an algorithm to implement git diff (Only text files diff)
//git diff algorithm

std::string git_diff(std::ifstream& f1, std::ifstream& f2) {
  if (!f1.good() || !f2.good() )
    throw("SOme file incorrect");

  std::string output;
  std::queue q1;
  std::queue q2;
  std::string s1;
  std::string s2;
  while( f1.good() && f2.good()) {
    std::getline(f1, s1);
    std::getline(f2, s2);

    while ( s1.compare(s2) != 0 && q2.empty()) {
      s.append(" --- " + s1+"\n");
//      s1 = f1.readline();
    }
    if (s1.compare(s2) != 0) {
      q1.push(s1+"\n");
      q2.push(s2+"\n");
    } else {
      while (!q1.empty() ) {
        s.append(" --- " + q1.front());
        q1.pop();
      }
      while (!q2.empty()) {
        s.append(" +++ " + q2.front());
        q2.pop();
      }
    }
  }
  return s;

}

Write an algorithm to implement git diff (Only text files diff)

string git_diff(file* f1, file* f2) {
  if (!f1 || !f2 )
  throw(�File incorrect�);

  string s(��);
  stack st1;
  stack st2;
  while( f1.good() && f2.good()) {
    string s1 = f1.readline();
    string s2 = f2.readline();
    while ( s1.compare(s2) != 0 && st2.empty()) {
      s.append(� --- � + s1+�\n�);
      s1 = f1.readline();
    }
    if (s1.compare(s2) != 0) {
      st1.push(s1+�\n�);
      st2.push(s2+�\n�);
    } else {
      while (!st1.empty() ) {
        s.append(� --- �st1.top());
        st1.pop();
      }
      while (!st2.empty()) {
        s.append(� +++ �st2.top());
        st2.pop();
      }
    }
  }

}

  return s;
}

// 2. write function, to check whether there are two adjacent bits are 1, given a 32 bits integer

bool adj11(int n) {
if (abs(n<3))
return false;

while (n>0) {
  if ((n & 3) > 0 )
    return true;
  n = n>> 1;
}
return false;
}


#endif /* MOTO_H_ */
