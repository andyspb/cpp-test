/*
 * swap.h
 *
 *  Created on: Jan 9, 2016
 *      Author: andy
 */

#ifndef SRC_COMMON_SWAP_H_
#define SRC_COMMON_SWAP_H_

template<typename T>
void swap(T *a, T *b) {
  T tmp = *a;
  *a = *b;
  *b = tmp;
}

#endif /* SRC_COMMON_SWAP_H_ */
