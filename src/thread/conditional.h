/*
 * conditional.h
 *
 *  Created on: Aug 21, 2015
 *      Author: andy
 */

#ifndef SRC_THREAD_CONDITIONAL_H_
#define SRC_THREAD_CONDITIONAL_H_

#include <mutex>
#include <condition_variable>
#include <thread>
#include <chrono>

#include <type_traits>

#define merge(a,b) #b#a

namespace conditional_variable {

typedef std::conditional<sizeof(int) <= 4,
                         std::mt19937,
                         std::mt19937_64>::type Engine;

void fun(int n)
{
  int arr[n];
  // ......
}
class SayHello {
 public:
  void operator()() const {
    std::cout << "hello" << std::endl;
  }
};

std::mutex m;
std::condition_variable cv;
std::string data;
bool ready = false;
bool processed = false;

void worker_thread() {
  LOG(INFO) << __PRETTY_FUNCTION__;

  // Wait until main() sends data
  std::cout << "before cv.wait...\n";
  std::unique_lock<std::mutex> lk(m);
  std::cout << "Waiting... \n";
  cv.wait(lk, [] {
    std::cout << "return ready="<<ready<<'\n';
    return ready;
  });
  std::cout << "after cv.wait...\n";

  // after the wait, we own the lock.
  std::cout << "Worker thread is processing data\n";
  data += " after processing";

  // Send data back to main()
  processed = true;
  std::cout << "Worker thread signals data processing completed\n";

  // Manual unlocking is done before notifying, to avoid waking up
  // the waiting thread only to block again (see notify_one for details)
  lk.unlock();
  cv.notify_one();
}

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;

  std::cout << merge(36,12) << std::endl;
  fun(6);

//  SayHello hello;
//      std::thread t(hello);
//      t.join();

  std::thread worker(worker_thread);

  std::this_thread::sleep_for(std::chrono::seconds(2));

  data = "Example data";
  // send data to the worker thread
  {
    std::lock_guard<std::mutex> lk(m);
    ready = true;
    std::cout << "main() signals data ready for processing\n";
  }
  cv.notify_one();

  // wait for the worker
  {
    std::unique_lock<std::mutex> lk(m);
    cv.wait(lk, [] {return processed;});
  }
  std::cout << "Back in main(), data = " << data << '\n';

  worker.join();
  RETURN_OK();
}

}  // namespace conditional_variable

#endif /* SRC_THREAD_CONDITIONAL_H_ */
