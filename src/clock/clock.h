/*
 * clock.h
 *
 *  Created on: Nov 19, 2014
 *      Author: andy
 */

#ifndef CLOCK_H_
#define CLOCK_H_

#include <iostream>

namespace clock_ {

int test() {
  // Generate data
  const unsigned arraySize = 32768;
  int data[arraySize];

  for (unsigned c = 0; c < arraySize; ++c)
    data[c] = std::rand() % 256;

  // !!! With this, the next loop runs faster
  std::sort(data, data + arraySize);

  // Test
  clock_t start = clock();
  long long sum = 0;

  for (unsigned i = 0; i < 100000; ++i)
  {
    // Primary loop
    for (unsigned c = 0; c < arraySize; ++c)
    {
      if (data[c] >= 128)
        sum += data[c];
    }
  }

  double elapsedTime = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;

  std::cout << elapsedTime << std::endl;
  std::cout << "sum = " << sum << std::endl;
  return 1;
}

} // namespace clock_


#endif /* CLOCK_H_ */
