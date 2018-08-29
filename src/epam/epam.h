/*
 * epam.h
 *
 *  Created on: 21 џэт. 2015 у.
 *      Author: andy
 */

#ifndef EPAM_H_
#define EPAM_H_

#include <stdio.h>
#include <map>
#include <iterator>
#include <iostream>

namespace epam {

//#1
//0x30-0x39
void test1() {
  char str[] = "12345";
  short *ptr = (short*) str;
  printf("%s\n", str);
  printf("%x\n", *ptr);
  printf("%x\n", *(ptr + 1));
}

//#2
char* fill_spaces(char* str) {  //str should end \n, check size
  int i(0);  // initialization
  const int s = strlen(str);  // get len;
  while (i < s) {
    str[i] = ' ';
    ++i;
  }
  return str;
}

//#3
//char g_arr[] = {0, 1, 1, 2, 1, ..};
int count_bits(uint32_t n) {
  int i(0);
  for (i = 0; n > 0; ++i) {
    n &= n - 1;
  }
  return i;
}

int NumberOfSetBits(int i) {
  i = i - ((i >> 1) & 0x55555555);
  i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
  return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

//#4

typedef std::map<std::string, int> mymap;
//typedef std::map<std::string, int>::iterator myiter;

void remove(mymap& m, int v) {
  //std::stack<string> s;
  mymap::iterator iter;
  for (iter = m.begin(); iter != m.end(); ++iter) {
    if (iter->second == v) {
      iter = m.erase(iter);
    }
  }
}

//#copy ctor

class Base {
 public:
  Base(int i)
      : data(i) {
  }
  ;
 private:
  int data;

  // Base(const Base& base);
  // Base& operator=(const Base& base);
};

int test() {
  std::cout << "epam tests\n";
  test1();

  for (uint32_t n = 1; n <= 32; ++n) {
    std::cout << " bits in " << n << " = " << count_bits(n) << "\n";
    std::cout << " bits in " << n << " = " << NumberOfSetBits(n) << "\n";
  }

  mymap m;
  m.insert(std::pair<std::string, int>("1", 1));
  m.insert(std::pair<std::string, int>("4", 4));
  m.insert(std::pair<std::string, int>("3", 3));
  m.insert(std::pair<std::string, int>("2", 2));
  m.insert(std::pair<std::string, int>("5", 5));

  mymap::iterator iter;
  for (iter = m.begin(); iter != m.end(); ++iter) {
    std::cout << iter->second << " ";
  }
  std::endl(std::cout);

  remove(m, 3);
  for (iter = m.begin(); iter != m.end(); ++iter) {
    std::cout << iter->second << " ";
  }
  std::endl(std::cout);

  std::vector<Base> vb;
  vb.push_back(Base(1));

  return 1;
}

}  // namespace epam

#endif /* EPAM_H_ */
