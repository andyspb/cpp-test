//  tests10.h
//  author: andrey.krutogolov@gmail.com
//  date:   21.03.2013

#ifndef TESTS10_H_
#define TESTS10_H_

#include <string>
#include <iostream>

#include <boost/lexical_cast.hpp>
using namespace std;

namespace tests10 {

string convertInt(int number) {
  if (number == 0)
    return "0";
  string temp = "";
  string returnvalue = "";
  while (number > 0) {
    temp += number % 10 + 48;
    number /= 10;
  }
  for (size_t i = 0; i < temp.length(); ++i)
    returnvalue += temp[temp.length() - i - 1];
  return returnvalue;
}

string convertInt2(int number) {
  stringstream ss;  //create a stringstream
  ss << number;  //add number to the stream
  return ss.str();  //return a string with the contents of the stream
}

int main() {
  string s = boost::lexical_cast<string>(10);
  cout << "s: " << s << endl;

  int i = 0xDEADBEEF;  // some 32-bit integer
  char buffer[16] = { 0 };
  sprintf(buffer, "%i.%i.%i.%i", (i >> 24) & 0xFF, (i >> 16) & 0xFF,
          (i >> 8) & 0xFF, i & 0xFF);
  cout << "buffer: " << buffer << endl;
  string ss(buffer);
  cout << "ss: " << ss << endl;
  return 0;
}

}  // namespace tests10

#endif  // TESTS10_H_
