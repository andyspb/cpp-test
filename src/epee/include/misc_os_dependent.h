#ifndef MISC_OS_DEPENDENT_H
#define MISC_OS_DEPENDENT_H

namespace epee {
namespace misc_utils {

#if !defined(__GNUC__)
inline boost::uint64_t get_tick_count()
{
  return ::GetTickCount64();
}
#else
inline boost::uint64_t get_tick_count() {
//  struct timespec ts;
//  if (clock_gettime(CLOCK_MONOTONIC, &ts) != 0) {
//    return 0;
//  }
//  return (ts.tv_sec * 1000) + (ts.tv_nsec / 1000000);
#include <sys/time.h>
  timeval tv;
  gettimeofday(&tv, 0);
  // return milliseconds;
  return (tv.tv_sec * 1000);
}
#endif // !defined(__GNUC__)

inline
int call_sys_cmd(const std::string& cmd) {
  std::cout << "# " << cmd << std::endl;

  FILE * fp;
  //char tstCommand[] ="ls *";
  char path[1000] = { 0 };
#if !defined(__GNUC__)
  fp = _popen(cmd.c_str(), "r");
#else
  fp = popen(cmd.c_str(), "r");
#endif // !defined(__GNUC__)
  while (fgets(path, 1000, fp) != 0)
    std::cout << path;

#if !defined(__GNUC__)
  _pclose(fp);
#else
  pclose(fp);
#endif  // !defined(__GNUC__)
  return 0;

}

inline std::string get_thread_string_id() {
#if defined (_MSC_VER)
  return boost::lexical_cast<std::string>(GetCurrentThreadId());
#elif defined(__GNUC__)
//#include <pthread.h>
//  pthread_t pid(pthread_self());
//  return boost::lexical_cast<std::string>(pid.p);
  return std::string();
#endif  // defined (_MSC_VER)
}
} // namespace misc_utils
} // namespace epee

#endif // MISC_OS_DEPENDENT_H

