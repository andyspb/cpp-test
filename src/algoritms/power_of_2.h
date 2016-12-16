#ifndef _POWER_OF_TWO_H_
#define _POWER_OF_TWO_H_

#define power_of_two(x) ((x)&&(!( x & (x-1) ) ))

namespace power_of_two {

void power_of_2() {
  printf("Test power of 2\n");
  for (int i = 0; i <= 100; i += 4) {
    printf("power_of_two(%d)=%d\n", i, power_of_two(i));
  }
}

}  // namespace power_of_two

#endif  // _POWER_OF_TWO_H_
