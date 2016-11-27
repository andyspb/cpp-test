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
#include <iomanip>

#define LOG(LEVEL) tlog::Log<tlog::Level::LEVEL>().Get()
#define __ENTER__ " >>> "
#define __EXIT__ " <<< "

#ifdef _MSC_VER
#define __PRETTY_FUNCTION__  __FUNCTION__
#endif

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

class ScopeLog {
public:
  ScopeLog(const std::string& from) : from_(from){
    LOG(INFO) << from_ << __ENTER__;
  }
  ~ScopeLog() {
    LOG(INFO) << from_ << __EXIT__;
  }

private:
  const std::string from_;
};

#ifdef _WIN32
#define __SCOPE_LOG__ ScopeLog _(__FUNCTION__)
#else
#define __SCOPE_LOG__ ScopeLog _(__PRETTY_FUNCTION__)
#endif

#endif /* SRC_LOGGER_LOG_TEMPLATE_H_ */
