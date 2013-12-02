//  tests8.h
//  author: andrey.krutogolov@gmail.com
//  date:   19.03.2013

#ifndef TESTS8_H_
#define TESTS8_H_

// Ð�Ð°Ð¿Ð¸ÑˆÐ¸Ñ‚Ðµ lock-free Ñ€ÐµÐ°Ð»Ð¸Ð·Ð°Ñ†Ð¸ÑŽ ÐºÐ»Ð°Ñ�Ñ�Ð° Ñ� Ð¼ÐµÑ‚Ð¾Ð´Ð¾Ð¼ int next(),
// ÐºÐ¾Ñ‚Ð¾Ñ€Ñ‹Ð¹ Ð²Ð¾Ð·Ð²Ñ€Ð°Ñ‰Ð°ÐµÑ‚ Ñ�Ð»ÐµÐ¼ÐµÐ½Ñ‚Ñ‹ Ð°Ñ€Ð¸Ñ„Ð¼ÐµÑ‚Ð¸Ñ‡ÐµÑ�ÐºÐ¾Ð¹ Ð¿Ñ€Ð¾Ð³Ñ€ÐµÑ�Ñ�Ð¸Ð¸ 2 + (n - 1) * 3.
// ÐšÐ¾Ð´ Ð´Ð¾Ð»Ð¶ÐµÐ½ ÐºÐ¾Ñ€Ñ€ÐµÐºÑ‚Ð½Ð¾ Ñ€Ð°Ð±Ð¾Ñ‚Ð°Ñ‚ÑŒ Ð² Ð¼Ð½Ð¾Ð³Ð¾Ð¿Ð¾Ñ‚Ð¾Ñ‡Ð½Ð¾Ð¹ Ñ�Ñ€ÐµÐ´Ðµ.
// ÐŸÐ¾Ð´Ñ€Ð¾Ð±Ð½ÐµÐµ: http://company.yandex.ru/job/vacancies/dev_browser_principal.xml

#include <iostream>
// #include <atomic>

using namespace std;

namespace tests8 {

template <int n>
class T {
  enum {
    value = 2+ (T<n-1>::value)*3
  };
};

template<>
class T<1> {
  enum {
    value = 2
  };
};

class A {
  // lock-free
  int getNext() {
    return 0;
  }
};

int main() {
  return 0;
}

}  // namespace tests8


#endif  // TESTS8_H_
