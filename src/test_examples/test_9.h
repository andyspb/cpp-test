//  tests9.h
//  author: andrey.krutogolov@gmail.com
//  date:   20.03.2013

#ifndef TESTS9_H_
#define TESTS9_H_

//#include <pthread.h>
#include <iostream>

//#include <boost/thread.hpp>

using namespace std;

namespace test_9 {

// предолагаем что класс Locker корректно реализован


//class Bar {
// public:
//  void Add(int i, double d) {
// порядок вызова блокировки
//1.m_doubles_
//2.m_integers_
// возможен deadlock так как при вызове Find(int) ресурсы блокируются
// в обратном порядке
//    Locker auto_lock_d(m_doubles_);
//    Locker auto_lock_i(m_integers_);
//    integers_.push_back(i);
//    doubles_.push_back(d);
//  }
//

//  bool Find(int i) {
// порядок вызова блокировки
//1.m_integers_
//    Locker auto_lock(m_integers_);
//    if (std::find(integers_.begin(), integers_.end(), i) != integers_.end())
//      return true;
//    else
//2.m_integers_ внутри  Find(double(i))
//      return Find(double(i));
//  }
//
// метод должен возвращать bool
//  void Find(double d) {
//    Locker auto_lock(m_doubles_);
//    return std::find(doubles_.begin(), doubles_.end(), d) != doubles_.end());
//  }
//
// private:
//  std::vector<int> integers_;
//  std::vector<double> doubles_;
//  Mutex m_integers_;
//  Mutex m_doubles_;
//};

// typedef pthread_mutex_t Mutex;
//
// class Locker {
//  public:
//   Locker(Mutex m)
//       : mutex(m) {
//     mutex = PTHREAD_MUTEX_INITIALIZER;
//     pthread_mutex_lock(&mutex);
//   }
//   ~Locker() {
//     pthread_mutex_unlock(&mutex);
//   }
//  private:
//   Mutex mutex;
// };
//
// class Bar {
//  public:
//   void Add(int i, double d) {
//     cout << "Bar::Add()\n";
//     Locker auto_lock_d(m_doubles_);
//     Locker auto_lock_i(m_integers_);
//     integers_.push_back(i);
//     doubles_.push_back(d);
//   }
//
//   bool Find(int i) {
//     cout << "Find(int)" << endl;
//     Locker auto_lock(m_integers_);
//     if (std::find(integers_.begin(), integers_.end(), i) != integers_.end()) {
//       return true;
//     } else {
//       return Find(double(i));
//     }
//   }
//
//   bool Find(double d) {
//     cout << "Find(double)" << endl;
//     Locker auto_lock(m_doubles_);
//     return (std::find(doubles_.begin(), doubles_.end(), d) != doubles_.end());
//   }
//
//   void print() {
//     cout << "integers_: ";
//     for (int i = 0 ; i < (int)integers_.size(); ++i ) {
//       cout << integers_.at(i) << " ";
//     }
//     endl(cout);
//     cout << "doubles_: ";
//     for (int i = 0 ; i < (int)doubles_.size(); ++i ) {
//       cout << doubles_.at(i) << " ";
//     }
//     endl(cout);
//   }
//
//   void doSomeWork(void) {
//     cout << "Bar::doSomeWork()\n";
//     for (int i = 0; i < 10 ; ++i) {
//       Add(i, double(i+1));
//     }
//   }
//
//  private:
//   std::vector<int> integers_;
//   std::vector<double> doubles_;
//   Mutex m_integers_;
//   Mutex m_doubles_;
// };

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;

//   Bar bar;
//   bar.Add(0, 1);
//
//   boost::thread t1(boost::bind( &Bar::doSomeWork, &bar ));
//   boost::thread t2(boost::bind( &Bar::doSomeWork, &bar ));
//
//   bar.print();
//   bool found = bar.Find(3);
//   cout << "found: " << found << std::endl;
//
//   t1.join();
//   t2.join();
//
//
  RETURN_OK();
}
}  // namespace tests9

#endif  // TESTS9_H_
