/*
 * alignment.h
 *
 *  Created on: 01 ����. 2015 �.
 *      Author: andy
 */

#ifndef ALIGNMENT_H_
#define ALIGNMENT_H_

#include <stdio.h>
#include <iostream>

namespace alignment {

// Alignment requirements
// (typical 32 bit machine)

// char         1 byte
// short int    2 bytes
// int          4 bytes
// double       8 bytes

// structure A
typedef struct Struct_A {
  char c;
  short int s;
}  //__attribute__((packed, aligned(4)))
struct_a_;

// structure B
typedef struct Struct_B {
  short int s;
  char c;
  int i;
}  //__attribute__((packed, aligned(4)))
struct_b_;

// structure C
typedef struct Struct_C {
  char c;
  double d;
  int s;
}  //__attribute__((packed, aligned(4)))
struct_c_;

// structure D
typedef struct Struct_D {
  double d;
  int s;
  char c;
}  //__attribute__((packed, aligned(4)))
struct_d_;

TEST_RESULT test() {
  __SCOPE_LOG__;
#if defined(__linux__) || defined(__mingw64__)
  printf("sizeof(structa_t) = %lu\n", (long unsigned) sizeof(struct_a_));
  printf("sizeof(structb_t) = %lu\n", (long unsigned) sizeof(struct_b_));
  printf("sizeof(structc_t) = %lu\n", (long unsigned) sizeof(struct_c_));
  printf("sizeof(structd_t) = %lu\n", (long unsigned) sizeof(struct_d_));
#else
  std::cout << "sizeof(structa_t) = " << sizeof(struct_a_) << std::endl;
  std::cout << "sizeof(structb_t) = " << sizeof(struct_b_) << std::endl;
  std::cout << "sizeof(structc_t) = " << sizeof(struct_c_) << std::endl;
  std::cout << "sizeof(structd_t) = " << sizeof(struct_d_) << std::endl;
#endif

  RETURN_OK();
}
}

#endif /* ALIGNMENT_H_ */
