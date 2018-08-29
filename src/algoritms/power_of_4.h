/*
 * power_of_4.h
 *
 *  Created on: 25 џэт. 2015 у.
 *      Author: andy
 */

#ifndef POWER_OF_4_H_
#define POWER_OF_4_H_

namespace power_of_4 {

#define power_of_two(x) ((x)&&(!( x & (x-1) )) && x & 0x55555555)

bool fn(unsigned int x) {
  if (x == 0)
    return false;
  if (x & (x - 1))
    return false;
  return x & 0x55555555;
}

}  // namespace power_of_4

#endif /* POWER_OF_4_H_ */
