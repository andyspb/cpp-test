/*
 * array_size.h
 *
 *  Created on: Feb 27, 2016
 *      Author: andy
 */

#ifndef SRC_TEMPLATES_ARRAY_SIZE_H_
#define SRC_TEMPLATES_ARRAY_SIZE_H_

namespace array_size {
template<typename T, size_t n>
void findSize(T (&arr)[n]) {
  LOG(INFO) << sizeof(T) * n;
}

template<typename T, size_t n>
size_t size_of_array(T (&arr)[n]) {
  return sizeof(T) * n;
}

template<size_t n>
void findSize(char (&arr)[n]) {
  LOG(INFO) << sizeof(char) * n;
}

template<size_t n>
size_t size_of_array(char (&arr)[n]) {
  return sizeof(char) * n;
}

template<size_t n>
void findSize(int (&arr)[n]) {
  LOG(INFO) << sizeof(int) * n;
}

template<size_t n>
size_t size_of_array(int (&arr)[n]) {
  return sizeof(int) * n;
}

template<size_t n>
void findSize(long long (&arr)[n]) {
  LOG(INFO) << sizeof(char) * n;
}

template<size_t n>
size_t size_of_array(long long (&arr)[n]) {
  return sizeof(char) * n;
}

template<size_t n>
void findSize(double (&arr)[n]) {
  LOG(INFO) << sizeof(char) * n;
}

template<size_t n>
size_t size_of_array(double (&arr)[n]) {
  return sizeof(char) * n;
}

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;
  int a[10];
  LOG(INFO) << sizeof(a) << " ";
  findSize(a);

  int b[100];
  LOG(INFO) << sizeof(b) << " ";
  findSize(b);

  char c[10];
  LOG(INFO) << sizeof(c) << " ";
  findSize(c);

  return 0;
  RETURN_OK();
}

}  // namespace array_size

#endif /* SRC_TEMPLATES_ARRAY_SIZE_H_ */
