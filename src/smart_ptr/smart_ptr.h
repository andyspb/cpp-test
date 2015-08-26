//  smart_ptr.h
//  author: andrey.krutogolov@gmail.com
//  date:   12.03.2013

#ifndef SMART_PTR_H_
#define SMART_PTR_H_

#include <iostream>
#include <memory>

namespace smart_ptr_ {

//std::weak_ptr<int> gw;
//
//void f() {
//  if (auto spt = gw.lock()) {  // Has to be copied into a shared_ptr before usage
//    std::cout << *spt << "\n";
//  } else {
//    std::cout << "gw is expired\n";
//  }
//}

struct Base {
  Base() {
    std::cout << "  Base::Base()\n";
  }
  // Note: non-virtual destructor is OK here
  ~Base() {
    std::cout << "  Base::~Base()\n";
  }
};
struct Derived : public Base {
  Derived() {
    std::cout << "  Derived::Derived()\n";
  }
  ~Derived() {
    std::cout << "  Derived::~Derived()\n";
  }
};

void thr(std::shared_ptr<Base> p) {
  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::shared_ptr<Base> lp = p;  // thread-safe, even though the
                                 // shared use_count is incremented
  {
    static std::mutex io_mutex;
    std::lock_guard<std::mutex> lk(io_mutex);
    std::cout << "local pointer in a thread:\n" << "  lp.get() = " << lp.get()
              << ", lp.use_count() = " << lp.use_count() << '\n';
  }
}

class bar {
 public:
  void foo() {
    std::cout << "hello from member function" << std::endl;
  }
};

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;
  std::shared_ptr<Base> p = std::make_shared<Derived>();

  std::cout << "Created a shared Derived (as a pointer to Base)\n"
            << "  p.get() = " << p.get() << ", p.use_count() = "
            << p.use_count() << '\n';
  std::thread t1(thr, p), t2(thr, p), t3(thr, p);
  p.reset();  // release ownership from main
  std::cout << "Shared ownership between 3 threads and released\n"
            << "ownership from main:\n" << "  p.get() = " << p.get()
            << ", p.use_count() = " << p.use_count() << '\n';
  t1.join();
  t2.join();
  t3.join();
  std::cout << "All threads completed, the last one deleted Derived\n";
//  {
//    auto sp = std::make_shared<int>(42);
//    gw = sp;
//
//    f();
//  }

//  f();


//  std::thread t(&bar::foo, bar());
//  t.join();

  RETURN_OK();
}

}  // namespace smart_ptr

#endif  // SMART_PTR_H_
