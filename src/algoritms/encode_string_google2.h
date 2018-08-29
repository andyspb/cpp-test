/*
 * encode_string_google2.h
 *
 *  Created on: 26.07.2012
 *      Author: Andy
 */

#ifndef ENCODE_STRING_GOOGLE2_H_
#define ENCODE_STRING_GOOGLE2_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define FUNC(x,y)    \
if (  x!= y ) {      \
  (x) ^= (y);         \
  (y) ^= (x); \
  (x) ^= (y); \
}

namespace encode_string_google2 {

int test() {

//srand48(0);
//int i(0);
//const size_t n = 1000;
//int *tab = (int*) malloc(n * sizeof(int));
//for (i = 0; i < n; ++i) {
//  tab[i] = i;
//}
//for (i = 0; i < n; ++i) {
//  int i1 = (int) ceil(n * drand48());
//  int i2 = (int) ceil(n * drand48());
//  FUNC(tab[i1], tab[i2]);
//}
//
//for (i = 0; i < n; ++i)
//  printf("%d ", tab[i]);
//printf("\n");
//free(tab);
//return 0;
//}
//
//class File {
//String name;
//String[] dependencies();
//}
//
//Files[] files;
//
//File[] complierOrder(File[] files)
//
//}
//void compile(File file) {
//while (file.dep) {
//compile(dep)
//}
//print(file)
//}
  return 0;
}  // encode_string_google2

#endif /* ENCODE_STRING_GOOGLE2_H_ */
