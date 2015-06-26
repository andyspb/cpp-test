#ifndef _BLO_H_
#define _BLO_H_

#include <string.h>
#include <limits>
//using c-style only
using namespace std;
namespace blo {
int ROL(int a, int n) {
  int t1, t2;
  n = n % (sizeof(a) * 8);
  t1 = a << n;
  t2 = a >> (sizeof(a) * 8 - n);
  return t1 | t2;
}

int ROR(int a, int n) {
  int t1, t2;
  n = n % (sizeof(a) * 8);
  t1 = a >> n;
  t2 = a << (sizeof(a) * 8 - n);
  return t1 | t2;
}

unsigned int is_big_endian() {
  unsigned int i = 1;
  char ch = *(char*) &i;
  return (0 == ch);
}

//get most significant bit;
int get_MSB_position(unsigned int x) {
  if (!x)
    return -1;
  unsigned int pos = 0, temp = 0;
  for (int i = 0x10; i > 0; i >>= 1) {
    temp = x >> i;
    if (temp) {
      x = temp;
      pos += i;
    }
  }
  return pos + x;
}

//get least significant bit position
int get_LSB_position(unsigned int x) {
  if (x == 0)
    return -1;
  int pos = 32;
  if (x & 0xffff) {
    pos -= 16;
  } else {
    x >>= 16;
  };
  if (x & 0xff) {
    pos -= 8;
  } else {
    x >>= 8;
  }
  if (x & 0xf) {
    pos -= 4;
  } else {
    x >>= 4;
  }
  if (x & 0x3) {
    pos -= 2;
  } else {
    x >>= 2;
  }
  if (x & 1) {
    pos -= 1;
  }
  return pos;
}

int ** alloc_matrix(int i, int j) {
  int c;
  int ** matrix = (int **) malloc(sizeof(int*) * i);
  for (c = 0; c < i; c++) {
    matrix[c] = (int*) malloc(sizeof(int) * j);
  }
  return matrix;
}

int bits_shift() {
  int i = 15;
  char buffer[33] = { 0 };
  _itoa(i, buffer, 2);
  printf(" i=%d binary=%s\n", i, buffer);

  i = i >> 1;
  _itoa(i, buffer, 2);
  printf(" i=%d binary=%s\n", i, buffer);
  i = i >> 1;
  _itoa(i, buffer, 2);
  printf(" i=%d binary=%s\n", i, buffer);
  i = i >> 1;
  _itoa(i, buffer, 2);
  printf(" i=%d binary=%s\n", i, buffer);
  i = i >> 1;
  _itoa(i, buffer, 2);
  printf(" i=%d binary=%s\n", i, buffer);
  return 0;
}

void test() {
  int res = is_big_endian();
  printf("The system is %s\n", is_big_endian() ? "BE" : "LE");

  bits_shift();
#define VAL 0x12345678
//		printf("0x%X 0x%X 0x%X\n", VAL, ROL(VAL, 8), ROR(VAL, 8));
  exit(0);
  printf("###################################\n");

#pragma warning(disable:4996)
  for (int i = 0; i < 256; i += 5) {

    char buffer[32] = { 0 };
    itoa(i, buffer, 2);
    printf("MSB of %d \t(binary \t\t%s) \t= %d\n", i, buffer,
           get_MSB_position(i));
  }

  printf("###################################\n");

  for (unsigned int i = UINT_MAX/*numeric_limits<unsigned int>::max()*/; i > 0;
      i >>= 0xf) {
    if (i) {
      char buffer[33] = { 0 };
      itoa(i, buffer, 2);
      printf("LSB of %d \t(binary %s) \t= %d\n", i, buffer,
             get_LSB_position(i));
    }
  }

  int ** a = alloc_matrix(2, 3);

  a[0][0] = 5;
  a[1][2] = 10;

  return;
}
}  //namespace blo

#endif // _BLO_H_
