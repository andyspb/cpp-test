/*
 * lock_free_rung_buffer.h
 *
 *  Created on: May 31, 2016
 *      Author: andy
 */

#ifndef SRC_LOCK_FREE_LOCK_FREE_RING_BUFFER_H_
#define SRC_LOCK_FREE_LOCK_FREE_RING_BUFFER_H_

#include <thread>
#include <atomic>
#include <iostream>
#include <cinttypes>

using namespace std;

namespace lock_free_ring_buffer {

#define RING_BUFFER_SIZE 100
#define CYCLE            1000
class lockless_ring_buffer_spsc {
 public:

  lockless_ring_buffer_spsc() {
    write.store(0);
    read.store(0);
  }

  bool try_push(int64_t val) {
    const auto current_tail = write.load();
    const auto next_tail = increment(current_tail);
    if (next_tail != read.load()) {
      buffer[current_tail] = val;
      write.store(next_tail);
      return true;
    }

    return false;
  }

  void push(int64_t val) {
    while (!try_push(val))
      ;
  }

  bool try_pop(int64_t* pval) {
    auto currentHead = read.load();

    if (currentHead == write.load()) {
      return false;
    }

    *pval = buffer[currentHead];
    read.store(increment(currentHead));

    return true;
  }

  int64_t pop() {
    int64_t ret;
    while (!try_pop(&ret))
      ;
    return ret;
  }

 private:
  std::atomic<int64_t> write;
  std::atomic<int64_t> read;
  int64_t size = RING_BUFFER_SIZE;
  int64_t buffer[RING_BUFFER_SIZE];

  int64_t increment(int n) {
    return (n + 1) % size;
  }
};

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__ << " >>>";

  lockless_ring_buffer_spsc queue;

  std::thread write_thread([&] () {
    for(int i = 0; i<CYCLE; i++)
    {
      std::cout << "push:" << i << "\n";
      queue.push(i);
    }
  }  // End of lambda expression
      );
  std::thread read_thread([&] () {
    for(int i = 0; i<CYCLE; i++)
    {
      int64_t p = queue.pop();
      std::cout << "\t\tpop:" << p << "\n";
    }
  }  // End of lambda expression
      );
  write_thread.join();
  read_thread.join();

  LOG(INFO) << __PRETTY_FUNCTION__ << " <<<";
  RETURN_OK();
}

}  // namespace lock_free_rung_buffer

#endif /* SRC_LOCK_FREE_LOCK_FREE_RING_BUFFER_H_ */
