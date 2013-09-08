#ifndef _OBSERVER_H_
#define _OBSERVER_H_

#include <iostream>
#include <string>

namespace observer {
class Observer {
  public:
    virtual ~Observer() {
    }
    virtual void on_message(const std::string &)=0;
};

class MessageBoard {
    Observer& observer;
  public:
    MessageBoard(Observer & obs)
        : observer(obs) {
      std::cout << "Message board created, observer subscribed\n";
    }
    void post(const std::string & str) {
      observer.on_message(str);
    }
};

class Writer: public Observer {
  public:
    void on_message(const std::string& str) {
      std::cout << "on_message: " << str << std::endl;
    }
};

void hello_world(MessageBoard & message_board) {
  message_board.post("message_board->post the message:Hello world!");
}

int test() {
  std::cout << "Test: Observer pattern example --->" << std::endl;
  Writer writer;
  MessageBoard message_board(writer);
  hello_world(message_board);
  std::cout << "<--- test passed" << std::endl;
  return 1;
}
} // namespace observer

#endif // _OBSERVER_H_
