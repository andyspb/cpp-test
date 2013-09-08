#ifndef ENCODE_STRING_GOOGLE_H_
#define ENCODE_STRING_GOOGLE_H_

#include <stdio.h>

#include <sstream>
#include <iostream>
#include <string.h>

namespace encode_string_google {

template<class T>
std::string toString(T t) {
  std::stringstream s;
  s << t;
  return s.str();
}

// Encode string
std::string encode(const char *str_to_encode) {
  std::string out;
  if (!str_to_encode || strlen(str_to_encode) == 0) {
    return out;
  }
  char c = *str_to_encode;
  int counter = 1;
  while (*(++str_to_encode) != '\0') {
    if (*str_to_encode != c) {
      out.append(toString(counter));
      out.append(toString(c));
      counter = 1;
      c = *str_to_encode;
    } else {
      ++counter;
    }
  }
  out.append(toString(counter));
  out.append(toString(c));
  return out;
}

std::string decode(const char *str_to_decode) {
  std::string out;
  if (!str_to_decode) {
    return out;
  }
  int len = strlen(str_to_decode);
  if (len == 0) {
    return out;
  }
  if (len % 2 == 1) {
    throw "Odd length of encoded string is incorrect.";
  }
  char c;
  int counter(0);
  for (int i = 0; i < len; i += 2) {
    counter = str_to_decode[i] - '0';
    for (int j = 0; j < counter; ++j) {
      c = str_to_decode[i + 1];
      out.append(toString(c));
    }
  }
  return out;
}

int test() {
  std::cout << "Test: encode decode strings" << std::endl;
  const char *test = "1112223331188188";
  std::string encode_str(encode(test));
  std::cout << "Encode " << test << ": " << encode_str << std::endl;
  const char *test2 = encode_str.c_str();
  std::string decode_str(decode(test2));
  std::cout << "Decode " << encode_str << ": " << decode_str << std::endl;
  if (!strcmp(test, decode_str.c_str())) {
    std::cout << "Encoding-decoding is successful" << std::endl;
  } else {
    std::cout << "Encoding-decoding is failed" << std::endl;
  }
  return 1;
}
}

#endif /* ENCODE_STRING_GOOGLE_H_ */
