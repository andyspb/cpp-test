#include <iostream>
#pragma once

char * ItoaTest(int number);

void TestMyItoa(int number) {
  std::cout << ItoaTest(number) << std::endl;
}

char * ItoaTest(int number) {
  std::cout << "ItoaTest number=" << number << std::endl;
  if (number == 0) {
    char * ret;
    ret = (char *) malloc(2 * sizeof(char));
    *ret = '0';
    *(ret + 1) = '\0';
    return ret;
  } else {

    char buff[8];
    bool isNegative = (number < 0);
    buff[0] = '\0';
    int i = 0;

    if (isNegative) {
      number = number * (-1);
    }

    while (number != 0) {
      buff[++i] = number % 10 + char('0');
      number = number / 10;
    }

    if (isNegative) {
      buff[++i] = '-';

    }

    int m = i >> 1;
    for (int j = 0; j <= m; j++) {
      char ch = buff[j];
      buff[j] = buff[i - j];
      buff[i - j] = ch;
    }

    char * ret;
    ret = (char *) malloc((i + 1) * sizeof(char));

    memcpy(ret, buff, (i + 1) * sizeof(char));

    return ret;
  }
}
