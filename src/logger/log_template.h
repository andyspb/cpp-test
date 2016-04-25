/*
 * log_template.h
 *
 *  Created on: 25 ���� 2015 �.
 *      Author: andy
 */

#ifndef SRC_LOGGER_LOG_TEMPLATE_H_
#define SRC_LOGGER_LOG_TEMPLATE_H_

#include <cstdio>
#include <ctime>
#include <sstream>

#define LOG(LEVEL) tlog::Log<tlog::Level::LEVEL>().Get()

namespace tlog {

enum Level {
  ERROR,
  WARNING,
  INFO,
  DEBUG
};

::std::string NowTime() {
  time_t t = time(0);
  tm *now = localtime(&t);
  ::std::stringstream ss;
  ss << now->tm_hour << ":" << now->tm_min << ":" << now->tm_sec;
  return ss.str();
}

::std::string LevelToString(const Level& log_level) {
  switch (log_level) {
    case Level::ERROR:
      return "ERROR";
      break;
    case Level::WARNING:
      return "WARNING";
      break;
    case Level::INFO:
      return "INFO";
      break;
    case Level::DEBUG:
      return "DEBUG";
      break;
    default:
      return "UNKNOWN";
  }
}

template<Level logLevel>
class Log {
 public:
  Log();
  virtual ~Log();
  ::std::ostringstream& Get();

 private:
  Log(const Log&);
  Log& operator=(const Log&);

 protected:
  ::std::ostringstream os_;

 private:
  Level log_level_;

};

template<>
Log<ERROR>::Log()
    : log_level_(ERROR) {
}
template<>
Log<WARNING>::Log()
    : log_level_(WARNING) {
}
template<>
Log<INFO>::Log()
    : log_level_(INFO) {
}
template<>
Log<DEBUG>::Log()
    : log_level_(DEBUG) {
}

template<Level logLevel>
Log<logLevel>::~Log() {
  os_ << std::endl;
  fprintf(stdout, "%s", os_.str().c_str());
  fflush(stdout);
}

template<Level logLevel>
::std::ostringstream& Log<logLevel>::Get() {
  os_ << "--- [" << NowTime();
  os_ << " " << LevelToString(log_level_) << "] ";
  return os_;
}

}  // namespace tlog

#endif /* SRC_LOGGER_LOG_TEMPLATE_H_ */
