#pragma once
#include <stdarg.h>
#include <stdio.h>

void trace(const char *format, ...) {
  char buf[2048];

  va_list arglist;

  // get the arg list and format it into a string
  va_start(arglist, format);
  vsprintf_s(buf, 2048, format, arglist);
  va_end(arglist);

  //vprintf_s(buf);            // prints to the standard output stream
  OutputDebugString(buf);    // prints to the output window
}

