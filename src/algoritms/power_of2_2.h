#pragma once

void print_check(int y);

void ms_test_power_of2() {

  print_check(1);
  print_check(2);
  print_check(4);
  print_check(8);
  print_check(16);
  print_check(32);
  print_check(9);
  print_check(12);
  print_check(14);
  print_check(22);
  print_check(26);
  print_check(0);
}

void print_check(int x) {
  printf(" (%d & (%d - 1))=%d\n", x, x, (x & (x - 1)));
}
