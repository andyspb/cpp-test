/*
 * pow.h
 *
 *  Created on: 25 ���. 2015 �.
 *      Author: andy
 */

#ifndef POW_H_
#define POW_H_

namespace pow2 {

/* Function to calculate x raised to the power y */
int power(int x, unsigned int y)
{
    if( y == 0)
        return 1;
    else if (y%2 == 0)
        return power(x, y/2)*power(x, y/2);
    else
        return x*power(x, y/2)*power(x, y/2);

}

/* Function to calculate x raised to the power y in O(logn)*/
int power2(int x, unsigned int y)
{
    int temp;
    if( y == 0)
        return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return temp*temp;
    else
        return x*temp*temp;
}

/* Program to test function power */
int main()
{
    int x = 2;
    unsigned int y = 3;

    printf("%d", power(x, y));
    getchar();
    return 0;
}

}  // namespace pow



#endif /* POW_H_ */
