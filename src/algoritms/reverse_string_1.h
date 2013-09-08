//Write a method that will reverse a string.
#pragma once
#include <iostream>

using namespace std;

void ReverseString(char *str) {
  int length = static_cast<int>(strlen(str));
  if (length <= 1) {
    return;
  }
  char temp;
  for (int i = 0; i < length >> 1; i++) {
    temp = str[length - i - 1];
    str[length - i - 1] = str[i];
    str[i] = temp;
  }
}

void StrReverse4(char *str) {
  if (*str) {
    StrReverse4(str + 1);
    putchar(*str);
    putchar('_');
  }
}

void ReverseStringTest() {
  cout << "Reverse string test" << endl;
  char strForReverse[] = "This is a string for reverse.";
  cout << "test string before reversing:" << strForReverse << endl;
  ReverseString(strForReverse);
  cout << "test string after reversing:" << strForReverse << endl;
  ReverseString(strForReverse);
  StrReverse4(strForReverse);
  //    cout<<"test string after reversing:"<<strForReverse<<endl;
  cout << endl;
}
