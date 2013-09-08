#ifndef _STATE_H_
#define _STATE_H_

#include <iostream>
#include <string>

namespace state {
class StateContext;
class State {
  public:
    virtual ~State() {
    }
    virtual void writeName(StateContext * stateContext, std::string name) {
    }
};

class StateA: public State {
  public:
    virtual ~StateA() {
    }
    StateA() {
    }
    virtual void writeName(StateContext * stateContext, std::string name);
};

class StateB: public State {
  public:
    virtual ~StateB() {
    }
    StateB() {
      count = 0;
    }
    virtual void writeName(StateContext * stateContext, std::string name);

  private:
    int count;
};

class StateContext {
  public:
    StateContext() {
      setState(new StateA());
    }
    ~StateContext() {
      delete (myState);
    }
    // normally only called by classes implementing the State interface
    void setState(State * newState) {
      myState = newState;
    }
    void writeName(std::string name) {
      myState->writeName(this, name);
    }

  private:
    State * myState;
};

//The context class has a state variable which it instantiates in an initial state, in this case StateA. In its method, it uses the corresponding methods of the state object.
void StateA::writeName(StateContext * stateContext, std::string name) {
  std::cout << "state A:" << name << std::endl;
  stateContext->setState(new StateB());
}

void StateB::writeName(StateContext * stateContext, std::string name) {
  std::cout << "\tstate B:" << name << std::endl;
  if (++count > 1) {
    stateContext->setState(new StateA());
  }
}
int test() {
  std::cout << "Test: State pattern example --->" << std::endl;
  StateContext * sc = new StateContext();
  sc->writeName("Monday");
  sc->writeName("Tuesday");
  sc->writeName("Wednesday");
  sc->writeName("Thursday");
  sc->writeName("Saturday");
  sc->writeName("Sunday");
  delete (sc);
  std::cout << "<--- test passed" << std::endl;
  return 1;
}
}  // namespace state

#endif // _STATE_H_
