#include <stdio.h>
#include <stdlib.h>

#include <iostream>
using namespace std;

int StdoutRedirectionTest(void) {
  FILE *stream;
  cout << "StdoutRedirectionTest" << endl;
  if ((stream = freopen("file.txt", "w", stdout)) == NULL) {
    return -1;
  }
  printf("this is stdout output\n");
  stream = freopen("CON", "w", stdout);
  printf("And now back to the console once again\n");

  return 0;
}
