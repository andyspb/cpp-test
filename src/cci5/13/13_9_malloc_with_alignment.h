/*
 * 13_9_malloc_with_alignment.h
 *
 *  Created on: 05 џэт. 2015 у.
 *      Author: andy
 */

#ifndef _MALLOC_WITH_ALIGNMENT_H_
#define _MALLOC_WITH_ALIGNMENT_H_

namespace malloc_with_align {

void* aligned_malloc(size_t required_bytes, size_t alignment) {
  void* p1;  // original block
  void** p2;  // aligned block
  int offset = alignment - 1 + sizeof(void*);
  if ((p1 = (void*) malloc(required_bytes + offset)) == 0) {
    return 0;
  }
  p2 = (void**) (((size_t)(p1) + offset) & ~(alignment - 1));
  p2[-1] = p1;
  return p2;
}

void aligned_free(void *p2) {
  /* for consistency., we use the same names as aligned_malloc*/
  void* p1 = ((void**) p2)[-1];
  free(p1);
}

int test() {
  return 1;
}

}  // namespace malloc_with_align

#endif /* _MALLOC_WITH_ALIGNMENT_H_ */
