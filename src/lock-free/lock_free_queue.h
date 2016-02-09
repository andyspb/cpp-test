// lock_free1.h
// author: andrey.krutogolov@gmail.com
// date:   27.03.2013

#ifndef LOCK_FREE_QUEUE_H_
#define LOCK_FREE_QUEUE_H_

#include <atomic>

namespace lock_free_queue {

template<typename T>
struct node {
  T value;
  std::atomic<node<T>*> next /**< Next node in list */;
};

struct _Queue {
//    node *head;
//    node *tail;
};

class LockFreeQueue {
};

TEST_RESULT main() {

  RETURN_OK();
}

}  // namespace lock_free1

#endif  // LOCK_FREE_QUEUE_H_
