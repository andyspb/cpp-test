/*
 * test_25.h
 *
 *  Created on: Apr 25, 2016
 *      Author: andy
 */

#ifndef SRC_TESTS_TEST_25_H_
#define SRC_TESTS_TEST_25_H_

#include <stdio.h>

namespace test_25 {

char* format_int_value_1(const char* format, int value)
{
    char buffer[80];
#pragma GCC diagnostic ignored "-Wreturn-local-addr"
#pragma GCC diagnostic push
//    static char buffer[80];
      sprintf(buffer, format, value);
    return buffer;
#pragma GCC diagnostic pop
}
char* format_int_value_2(const char* format, int value)
{
    static char buffer[80];
  LOG(INFO) << " buffer:" << buffer << " format:" << format << " value:"
      << value;
    sprintf(buffer, format, value);
    return buffer;
}
char* format_int_value_3(const char* format, int value)
{
    char* buffer = new char [80];
    LOG(INFO) << " buffer:" << buffer << " format:" << format << " value:"
        << value;
    sprintf(buffer, format, value);
    return buffer;
}
TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;

  printf("%s + %s = %s",
         format_int_value_2("%d", 5),
         format_int_value_2("%d", 6),
         format_int_value_2("%d", 5+6));


  printf("%s + %s = %s",
         format_int_value_3("%d", 5),
         format_int_value_3("%d", 6),
         format_int_value_3("%d", 5+6));



  LOG(INFO) << '\n';

  RETURN_OK();
}

}  // namespace test_25



#endif /* SRC_TESTS_TEST_25_H_ */
