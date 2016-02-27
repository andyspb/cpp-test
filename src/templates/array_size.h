/*
 * array_size.h
 *
 *  Created on: Feb 27, 2016
 *      Author: andy
 */

#ifndef SRC_TEMPLATES_ARRAY_SIZE_H_
#define SRC_TEMPLATES_ARRAY_SIZE_H_

namespace array_size {

template<size_t n>
void findSize(int (&arr)[n]) {
  LOG(INFO)  << sizeof(int) * n;
}

template<size_t n>
void findSize(char (&arr)[n]) {
  LOG(INFO)  << sizeof(char) * n;
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
