#pragma once
//Given only putchar (no sprintf, itoa, etc.)
//write a routine putlong that prints out an unsigned long in decimal.
//
//I gave the obvious solution of taking % 10 and / 10, which gives us the decimal value in reverse order.
//This requires an array since we need to print it out in the correct order.
//The interviewer wasn't too pleased and asked me to give a solution which didn't need the array.

void putlong(unsigned long x) {
  if (x >= 10) {
    putlong(x / 10);
  }
  putchar(x % 10 + 0x30);
}
void algo_5() {
  printf("algo_5 test:\n");
  unsigned long l = 1234567890;

  putlong(l);

  printf("\n");

}
