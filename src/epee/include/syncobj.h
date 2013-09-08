#ifndef __SYNCOBJ_H__
#define __SYNCOBJ_H__

#include <boost/thread/locks.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/recursive_mutex.hpp>

namespace epee {
// forward declaration
class critical_region;

class critical_section {
 public:
  //to make copy fake!
  critical_section(const critical_section& section) {
  }

  critical_section() {
  }

  ~critical_section() {
  }

  void lock() {
    m_section.lock();
  }

  void unlock() {
    m_section.unlock();
  }

  bool tryLock() {
    return m_section.try_lock();
  }

  // to make copy fake
  critical_section& operator=(const critical_section& section) {
    return *this;
  }

 private:
  boost::recursive_mutex m_section;

};

class critical_region {
 public:
  critical_region(critical_section &cs) {
    m_locker = &cs;
    cs.lock();
  }

  ~critical_region() {
    m_locker->unlock();
  }
 private:
  critical_region(const critical_region&);

  epee::critical_section *m_locker;

};

#if defined(WINDWOS_PLATFORM)
class shared_critical_section
{
public:
  shared_critical_section()
  {
    ::InitializeSRWLock(&m_srw_lock);
  }
  ~shared_critical_section()
  {}

  bool lock_shared()
  {
    AcquireSRWLockShared(&m_srw_lock);
    return true;
  }
  bool unlock_shared()
  {
    ReleaseSRWLockShared(&m_srw_lock);
    return true;
  }
  bool lock_exclusive()
  {
    ::AcquireSRWLockExclusive(&m_srw_lock);
    return true;
  }
  bool unlock_exclusive()
  {
    ::ReleaseSRWLockExclusive(&m_srw_lock);
    return true;
  }
private:
  SRWLOCK m_srw_lock;

};

class shared_guard
{
public:
  shared_guard(shared_critical_section& ref_sec):m_ref_sec(ref_sec)
  {
    m_ref_sec.lock_shared();
  }

  ~shared_guard()
  {
    m_ref_sec.unlock_shared();
  }

private:
  shared_critical_section& m_ref_sec;
};

class exclusive_guard
{
public:
  exclusive_guard(shared_critical_section& ref_sec):m_ref_sec(ref_sec)
  {
    m_ref_sec.lock_exclusive();
  }

  ~exclusive_guard()
  {
    m_ref_sec.unlock_exclusive();
  }

private:
  shared_critical_section& m_ref_sec;
};

class event
{
public:
  event() {
    m_hevent = ::CreateEvent(NULL, FALSE, FALSE, NULL);
  }

  ~event() {
    ::CloseHandle(m_hevent);
  }

  bool set() {
    return ::SetEvent(m_hevent) ? true:false;
  }

  bool reset() {
    return ::ResetEvent(m_hevent) ? true:false;
  }

  HANDLE get_handle() {
    return m_hevent;
  }

private:
  HANDLE m_hevent;
};
#endif

#define  SHARED_CRITICAL_REGION_BEGIN(x) \
  {\
    shared_guard  critical_region_var(x)
#define  EXCLUSIVE_CRITICAL_REGION_BEGIN(x) \
  {\
    exclusive_guard  critical_region_var(x)

#define  CRITICAL_REGION_LOCAL(x) \
  critical_region  critical_region_var(x)
#define  CRITICAL_REGION_BEGIN(x) \
  {\
    critical_region  critical_region_var(x)
#define  CRITICAL_REGION_END()  \
  }

#if defined(WINDWOS_PLATFORM)
inline const char* get_wait_for_result_as_text(DWORD res) {
  switch (res) {
    case WAIT_ABANDONED:
      return "WAIT_ABANDONED";
    case WAIT_TIMEOUT:
      return "WAIT_TIMEOUT";
    case WAIT_OBJECT_0:
      return "WAIT_OBJECT_0";
    case WAIT_OBJECT_0 + 1:
      return "WAIT_OBJECT_1";
    case WAIT_OBJECT_0 + 2:
      return "WAIT_OBJECT_2";
    default:
      return "UNKNOWN CODE";
  }
}
#endif  // defined(WINDWOS_PLATFORM)

}  // namespace epee

#endif  // __SYNCOBJ_H__
