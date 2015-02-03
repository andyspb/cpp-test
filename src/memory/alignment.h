/*
 * alignment.h
 *
 *  Created on: 01 ����. 2015 �.
 *      Author: andy
 */

#ifndef ALIGNMENT_H_
#define ALIGNMENT_H_

#include <stdio.h>

namespace alignment {


// Alignment requirements
// (typical 32 bit machine)

// char         1 byte
// short int    2 bytes
// int          4 bytes
// double       8 bytes

// structure A
typedef struct structa_tag
{
   char        c;
   short int   s;
} //__attribute__((packed, aligned(4)))
structa_t;

// structure B
typedef struct structb_tag
{
   short int   s;
   char        c;
   int         i;
} //__attribute__((packed, aligned(4)))
structb_t;

// structure C
typedef struct structc_tag
{
   char        c;
   double      d;
   int         s;
} //__attribute__((packed, aligned(4)))
structc_t;

// structure D
typedef struct structd_tag
{
   double      d;
   int         s;
   char        c;
} //__attribute__((packed, aligned(4)))
structd_t;

int test()
{
#ifdef __linux__
  printf("sizeof(structa_t) = %lu\n", sizeof(structa_t));
  printf("sizeof(structb_t) = %lu\n", sizeof(structb_t));
  printf("sizeof(structc_t) = %lu\n", sizeof(structc_t));
  printf("sizeof(structd_t) = %lu\n", sizeof(structd_t));
#else
  printf("sizeof(structa_t) = %d\n", sizeof(structa_t));
  printf("sizeof(structb_t) = %d\n", sizeof(structb_t));
  printf("sizeof(structc_t) = %d\n", sizeof(structc_t));
  printf("sizeof(structd_t) = %d\n", sizeof(structd_t));
#endif

   return 1;
}
}


#endif /* ALIGNMENT_H_ */
