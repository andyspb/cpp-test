// logger.h
// author: andrey.krutogolov@gmail.com
// date:   09.04.2013

#ifndef LOGGER_H_
#define LOGGER_H_

#define MISC_LOG_REG_NAME_ENABLE_LOG      "EnableDebugLog"
#define MISC_LOG_REG_NAME_LOG_LEVEL       "DebugLogLevel"
#define MISC_LOG_REG_NAME_LOG_PATH        "DebugLogPath"

#define MISC_LOG_DEBUG_NO_LOG_DATE        0x0001
#define MISC_LOG_DEBUG_WRITE_LOGFILES     0x0002
#define MISC_LOG_DEBUG_TRACE_DEBUG        0x0004
#define MISC_LOG_DEBUG_HELP               0x0008
#define MISC_LOG_DEBUG_TEXTONLY           0x0010
#define MISC_LOG_DEBUG_LOG_THREADID       0x0020
#define MISC_LOG_DEBUG_LOG_PROCID         0x0040

#define MISC_LOG_DEBUG_ALLOCATE_CONSOLE   0x1000
#define MISC_LOG_DEBUG_FORCE_LOG_DIRECT   0x2000

#include "utils.h"
#include "syncobj.h"
#include "log_opt_defs.h"
#include "misc_log_ex.h"

namespace epee {
namespace logger {

int test() {
  log_space::get_set_log_detalisation_level(true, LOG_LEVEL_2);
  log_space::log_singletone::add_logger(LOGGER_CONSOLE, NULL, NULL);

  LOG_PRINT("[Logger LOG_PRINT]", LOG_LEVEL_0);
  LOG_ERROR("[Logger LOG_ERROR]");
  return 1;
}

}  // namespace logger

}  // namesapce epee

#endif  // LOGGER_H_
