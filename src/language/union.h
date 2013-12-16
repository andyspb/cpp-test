#ifndef _UNION_H_
#define _UNION_H_

#include <stdlib.h>
#include <string>
#include <iostream>

namespace union_ {
union U {
    int i;
    float f;
    U() {
      i = 0;
      f = 1;
    }
};

union Union {
    int a;
    char b[10];
    float c;
};

int test() {
  U u;
  std::cout << "u.i=" << u.i << std::endl;
  std::cout << "u.f=" << u.f << std::endl;
  std::cout << "size" << sizeof(U) << std::endl;

  Union x,y;
  x.a = 50;
  strcpy(x.b, "hello");
  x.c = 21.50;

//  std::cout << "Union x:" << x.a  << " " << x.b << " " << x.c << std::endl;
//  std::cout << "Union y:" << y.a << " " << y.b  << " "<< y.c << std::endl;

  printf( "Union x: %d, %s, %f ", x.a, x.b, x.c);
  printf( "Union y: %d, %s, %f ", y.a, y.b, y.c);

  return 1;
}
} // namespace union_

#endif  // _UNION_H_
