#ifndef BYTE_ARRAY_2_STRING_H_
#define BYTE_ARRAY_2_STRING_H_

#include <iostream>
#include <string>

namespace byte_array_2_string {

char const hex[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A',
        'B', 'C', 'D', 'E', 'F' };

std::string byte_2_str(char* bytes, int size) {
  std::string str;
  for (int i = 0; i < size; ++i) {
    const char ch = bytes[i];
    str.append(&hex[(ch & 0xF0) >> 4], 1);
    str.append(&hex[ch & 0xF], 1);
  }
  return str;
}

int test() {
  std::cout << "Test: byte array to string --->" << std::endl;
  char arr[] = { (char) 0xAB, (char) 0x1C, (char) 0xFF, (char) 0x11 };
  int size = sizeof(arr) / sizeof(arr[0]);
  char arr_empty[] = { 0 };
  int size_empty = sizeof(arr_empty) / sizeof(arr_empty[0]);
  std::cout << byte_2_str(arr, size) << std::endl;
  std::cout << byte_2_str(arr_empty, size_empty) << std::endl;
  return 1;
}
}  // namespace byte_array_2_string

#endif /* BYTE_ARRAY_2_STRING_H_ */
