//  tests11.h
//  author: andrey.krutogolov@gmail.com
//  date:   22.03.2013

#ifndef TESTS11_H_
#define TESTS11_H_

#include <stdio.h>

namespace test_11 {
//auto int a=5;
TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;

//  int a = 5;
//  float b;
//  printf("%d\n", sizeof(++a + b));
//  printf(" %d\n", a);

//  char *str = new char();
//  scanf("%[^\n]", str);
//  printf("%s", str);
//  delete str;

//  int a = 320;
//  char *ptr;
//  ptr =( char *)&a;
//  printf("%d ",*ptr);

  int x = 0;
//    x=~a+a&a+a<<a;
  printf("%d", x);

  RETURN_OK();
}

}  // namespace tests11

#endif  // TESTS11_H_
