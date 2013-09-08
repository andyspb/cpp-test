
#include <iostream>

namespace observer_test {
class Observer {
  public:
    virtual ~Observer() {
    }
    virtual void update(const std::string& msg) = 0;
};
class Board {
    Observer& observer;
  public:
    Board(Observer& o)
        : observer(o) {
    }
    void post(const std::string& str) {
      observer.update(str);
    }
};

class Writer: public Observer {
  public:
    void update(const std::string& msg) {
      std::cout << __FUNCTION__ << "message:" << msg << std::endl;
    }
};

void test() {
  Writer w;
  Board b(w);
  b.post("aak044");

}
} // namespace observer_test
