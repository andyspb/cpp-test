/*
 * allocate_1024_bytes_of_memory.h
 *
 *  Created on: Feb 2, 2015
 *      Author: andy
 */

#ifndef ALLOCATE_1024_BYTES_OF_MEMORY_H_
#define ALLOCATE_1024_BYTES_OF_MEMORY_H_

namespace allocate_1024_bytes_of_memory {

int test() {

  {
    void *mem = malloc(1024 + 15);
    void *ptr = ((uintptr_t) mem + 15) & ~(uintptr_t) 0x0F;
    memset_16aligned(ptr, 0, 1024);
    free(mem);
  }

  return 1;
}
}

#endif /* ALLOCATE_1024_BYTES_OF_MEMORY_H_ */
