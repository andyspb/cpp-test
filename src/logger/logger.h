/*
 * logger.h
 *
 *  Created on: Nov 20, 2014
 *      Author: andy
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <stdio.h>

#define LOG_STR(s) \
  printf(" %s %s\n", __FILE__, s);

#define LOG_INT(i) \
  printf(" %s %d\n", __FILE__, i);

namespace logger {

class LogMethodWrapper {
 public:
  LogMethodWrapper(const char* str)
  : str_(str) {
    str_ = str;
    printf(">>>> %s >>>>\n", str_);
  }

  ~LogMethodWrapper() {
    printf("<<<< %s <<<<\n", str_);
  }
 private:
   const char* str_;
};

class LogMethodWrapperTab {
 public:
  LogMethodWrapperTab(const char* str)
  : str_(str) {
    str_ = str;
    printf("\t>>>> %s >>>>\n", str_);
  }

  ~LogMethodWrapperTab() {
    printf("\t<<<< %s <<<<\n", str_);
  }
 private:
   const char* str_;
};

}  // namespace logger

#endif /* LOGGER_H_ */
