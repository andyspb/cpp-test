/*
 * logger.h
 *
 *  Created on: Nov 20, 2014
 *      Author: andy
 */

#ifndef SRC_LOGGER_LOGGER_H_
#define SRC_LOGGER_LOGGER_H_

#include "log_template.h"

#include <stdio.h>
#include <stdarg.h>

#include <string>
#include <sstream>

#define MAX_MESSAGE_SIZE 1024

namespace logger {

void Trace(const char* msg, ...) {
  __SCOPE_LOG__;

  char temp_buff[MAX_MESSAGE_SIZE];
  char* pStr = 0;
  if (msg) {
    va_list args;
    va_start(args, msg);
    vsnprintf(temp_buff, MAX_MESSAGE_SIZE - 1, msg, args);
    va_end(args);
    pStr = temp_buff;
  }

  std::string str(pStr);

  LOG(INFO) << "str: " << str;
}

void Trace2(const char* msg, const char* msg1, ...) {
  __SCOPE_LOG__;
  std::stringstream ss;
  char temp_buff[MAX_MESSAGE_SIZE];
  char* pStr = 0;
  va_list args;
  va_start(args, msg1);
  vsnprintf(temp_buff, MAX_MESSAGE_SIZE - 1, msg1, args);

  std::string str(pStr);

  LOG(INFO) << "str: " << str;
}



int test(){
  __SCOPE_LOG__;

  const char test[] = "This is a test string";
  //Trace("[ [%s:%d] %s, %d ]", __PRETTY_FUNCTION__, __LINE__, test, 123);
  
#ifdef _WIN32
  Trace("[ [%s:%d] %s, %d ]", __FUNCTION__, __LINE__, test, 123);
#else
  Trace("[ [%s:%d] %s, %d ]", __PRETTY_FUNCTION__, __LINE__, test, 123);
#endif
  return 1;
}

}

#endif /* SRC_LOGGER_LOGGER_H_ */
