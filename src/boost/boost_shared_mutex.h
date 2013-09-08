#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <iostream>

boost::shared_mutex mux;
boost::mutex io_mux;

void msg(const char *str) {
  boost::mutex::scoped_lock l(io_mux);
  std::cout << str << std::endl;
} //msg

void share1() {
  mux.lock_shared();
  msg("share1 - lock_shared acquired");
  boost::this_thread::sleep(boost::posix_time::seconds(5));
  msg("share1 - unlocking shared");
  mux.unlock_shared();
} //share1

void unique() {
  msg("unique - try_lock");
  while (!mux.try_lock()) {
    boost::this_thread::sleep(boost::posix_time::seconds(1));
    msg("unique - try_lock");
  } //while

  msg("unique - acquired, unlocking");
  mux.unlock();
} //unique

void share2() {
  msg("share2 - try_lock_shared");
  while (!mux.try_lock_shared()) {
    boost::this_thread::sleep(boost::posix_time::seconds(1));
    msg("share2 - try_lock_shared");
  } //while

  msg("share2 - acquired, unlocking shared");
  mux.unlock_shared();
} //share

int LockTest2() {
  boost::thread_group tg;
  tg.create_thread(share1);
  boost::this_thread::sleep(boost::posix_time::microseconds(250));
  tg.create_thread(unique);
  boost::this_thread::sleep(boost::posix_time::microseconds(250));
  tg.create_thread(share2);

  tg.join_all();
  return 0;
}
