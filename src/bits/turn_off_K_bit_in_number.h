/*
 * turn_off_K_bit_in_number.h
 *
 *  Created on: 01 февр. 2015 г.
 *      Author: andy
 */

#ifndef TURN_OFF_K_BIT_IN_NUMBER_H_
#define TURN_OFF_K_BIT_IN_NUMBER_H_

#include <iostream>
using namespace std;

namespace turn_off_K_bit_in_number {

// Returns a number that has all bits same as n
// except the k'th bit which is made 0
int turnOffK(int n, int k)
{
    // k must be greater than 0
    if (k <= 0) return n;

    // Do & of n with a number with all set bits except
    // the k'th bit
    return (n & ~(1 << (k - 1)));
}

// Driver program to test above function
int main()
{
    int n = 15;
    int k = 4;
    cout << turnOffK(n, k);
    return 0;
}
}



#endif /* TURN_OFF_K_BIT_IN_NUMBER_H_ */
