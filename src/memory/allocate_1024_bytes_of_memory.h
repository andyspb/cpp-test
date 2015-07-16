/*
 * allocate_1024_bytes_of_memory.h
 *
 *  Created on: Feb 2, 2015
 *      Author: andy
 */

#ifndef ALLOCATE_1024_BYTES_OF_MEMORY_H_
#define ALLOCATE_1024_BYTES_OF_MEMORY_H_

#include <assert.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

namespace allocate_1024_bytes_of_memory {

static void memset_16aligned(void *space, char byte, size_t nbytes) {
  assert((nbytes & 0x0F) == 0);
  assert(((uintptr_t )space & 0x0F) == 0);
  memset(space, byte, nbytes);  // Not a custom implementation of memset()
}

int test() {
  {
    void *mem = malloc(1024 + 15);
    void *ptr = (void*) (((uintptr_t) mem + 15) & ~(uintptr_t) 0x0F);
    memset_16aligned(ptr, 0, 1024);
    free(mem);
  }

  return 1;
}
}

#endif /* ALLOCATE_1024_BYTES_OF_MEMORY_H_ */
