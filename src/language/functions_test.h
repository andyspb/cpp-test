#pragma once

int faktorial(int);
long long degree(int x, int y);
double sqrt(int v);

void ms_func_test() {

  printf("factorial(%d)=%d\n", 7, faktorial(7));

  printf("degree(%d,%d)=%lld\n", 10, 2, degree(2, 10));

  printf("sqrt(%d)=%4.2f\n", 256, sqrt(256));

}

int faktorial(int v) {
  if (v <= 1)
    return v;

  return v * faktorial(v - 1);

}

double sqrt(int v) {
  if (v < 0)
    return -1;
  if (v == 0)
    return 0;
  double s = v;
  for (int i = 0; i < 1000; i++) {

    s = (s + (v / s)) / 2;
  }
  return s;
}

long long degree(int x, int y) {
  if (y == 0)
    return 1;
  int value = x;
  long long result = x;
  while (--y > 0) {
    result *= value;
  }
  return result;
}
