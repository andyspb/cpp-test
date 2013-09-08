//  quiz_38.h
//  author: andrey.krutogolov@gmail.com
//  date:   09.03.2013

#ifndef QUIZ_38_H_
#define QUIZ_38_H_

namespace quiz_38 {

struct Foo {
  Foo(int d)
      : x(d) {
  }
  int x;
};

int test() {
  double x = 3.14;

  Foo f(x);

  std::cout << f.x << std::endl;

  return 1;
}

}  // namespace quiz_38

#endif  // QUIZ_38_H_
