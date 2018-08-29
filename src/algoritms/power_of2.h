#ifndef _ALGO_95_H
#define _ALGO_95_H

#define power_of_two(x) ((x)&&(!( x & (x-1) ) ))   

#endif //_ALGO_95_H

int algo_95() {
  printf("Test power of 2\n");
  printf("power_of_two(0)=%d\n", power_of_two(0));
  printf("power_of_two(2)=%d\n", power_of_two(2));
  printf("power_of_two(3)=%d\n", power_of_two(3));
  printf("power_of_two(4)=%d\n", power_of_two(4));
  printf("power_of_two(5)=%d\n", power_of_two(5));
  printf("power_of_two(6)=%d\n", power_of_two(6));
  printf("power_of_two(8)=%d\n", power_of_two(8));
  printf("power_of_two(510)=%d\n", power_of_two(510));
  printf("power_of_two(512)=%d\n", power_of_two(512));
  printf("power_of_two(1024)=%d\n", power_of_two(1024));

  return 0;
}
