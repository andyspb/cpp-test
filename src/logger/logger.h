/*
 * logger.h
 *
 *  Created on: Nov 20, 2014
 *      Author: andy
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <ctime>

enum LogLevel {
  ERROR,
  WARNING,
  INFO,
  DEBUG
};

namespace logger {

class Log {
 public:
  Log();
  virtual ~Log();
  ::std::ostringstream& Get(LogLevel level);

 private:
  Log(const Log&);
  Log& operator=(const Log&);

 protected:
  ::std::ostringstream os_;

 private:
  LogLevel log_level_;
};

::std::string NowTime() {
  time_t t = time(0);
  tm *now = localtime(&t);
  ::std::stringstream ss;
  ss << now->tm_hour << ":" << now->tm_min << ":" << now->tm_sec;
  return ss.str();
}

::std::string LevelToString(const LogLevel& log_level) {
  switch (log_level) {
    case LogLevel::ERROR:
      return "ERROR";
      break;
    case LogLevel::WARNING:
      return "WARNING";
      break;
    case LogLevel::INFO:
      return "INFO";
      break;
    case LogLevel::DEBUG:
      return "DEBUG";
      break;
    default:
      return "UNKNOWN";
  }
}

::std::ostringstream& Log::Get(LogLevel log_level) {
  os_ << "--- " << NowTime() << "\t";
  os_ << " " << LevelToString(log_level) << ": ";
  log_level_ = log_level;
  return os_;
}

Log::Log() : log_level_(LogLevel::ERROR) {
}

Log::~Log() {
  os_ << std::endl;
  fprintf(stdout, "%s", os_.str().c_str());
  fflush(stdout);
}

}  // namespace logger

#endif /* LOGGER_H_ */
