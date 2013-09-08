#ifndef _PROFILER_H_
#define _PROFILER_H_

#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <stdio.h>

namespace profiler {
struct Function;
static int counter = -1;
static std::queue<Function*> calls;

#define _START_ calls.push(new Function(std::string(__FUNCTION__), start, ++counter));
#define _END_ calls.push(new Function(std::string(__FUNCTION__), end, ++counter));
void a();
void b();
void c();

enum Action {
  start, end
};

struct Function {
    Function(std::string n, Action a, int t)
        : name(n), action(a), time(t) {
    }
    std::string name;
    Action action;
    int time;
};
void unit_test(int);
void print_calls(std::queue<Function*> calls);
int getInclusive(std::queue<Function*>, char);
int getExclusive(std::queue<Function*>, char);

//the function is unit test for a, b, c functions invocation
int test() {
  std::cout << "Test: Profiler pattern example --->" << std::endl;
  //set here recursion level
  unit_test(3);
  print_calls(calls);

  std::cout << "\nname\tinclusive\texclusive\n";
  for (char ch = 'a'; ch <= 'c'; ch++) {
    std::cout << ch << "\t" << getInclusive(calls, ch) << "\t\t"
        << getExclusive(calls, ch) << std::endl;
  }
  while (!calls.empty()) {
    Function* f = (Function*) calls.front();
    calls.pop();
    delete (f);
  }
  std::cout << "<--- test passed" << std::endl;
  return 1;
}

void print_calls(std::queue<Function*> calls) {
  while (!calls.empty()) {
    Function * f = (Function*) calls.front();
    std::cout << f->name << "\t" << (f->action ? "\tend" : "start\t") << "\t"
        << f->time << "\n";
    calls.pop();
  }
}

/*
 in the function I suppose to calculate inclusive time for every function. I mean if the function has recursion then
 only one top layer of the recursion will be calculated.
 Using stack to insert/remove function call.
 */
int getInclusive(std::queue<Function*> que, char ch) {
  int ret = 0;
  std::stack<Action> s;
  while (que.size()) {
    Function* f = (Function*) que.front();
    if (strchr((f->name).c_str(), ch)) {
      if (f->action == start) {
        if (s.size() == 0) {
          ret = ret - (f->time);
        }
        s.push(f->action);
      }
      if (f->action == end) {
        if (!s.size()) {
          return -1;
        }
        s.pop();
        if (s.size() == 0) {
          ret = ret + (f->time);
        }
      }

    }
    que.pop();
  }

  return ret;
}

/*
 In this particular  function for each function I calculate
 time after start "start" till calling next function and
 I calculate time before "end" calling	after previous function calling.
 Using stack to get function calls in backward direction and using stack
 to keep "end" invocation.
 */
int getExclusive(std::queue<Function*> que, char ch) {
  std::stack<Function *> s;
  std::stack<Function *> ends;
  Function* f = 0;
  int ret = 0;
  while (que.size()) {
    f = (Function*) que.front();
    if (f)
      s.push(f);
    que.pop();
  }
  int timer = f->time;
  while (s.size()) {
    f = (Function*) s.top();
    int delta = timer - f->time;
    timer = f->time;
    if (strchr((f->name).c_str(), ch)) {
      if (f->action == end) {
        ends.push(f);
      } else {
        ret += delta;
        //printf("timer=%d, %c, %d, %d\n", timer, ch, f->action, ret);
        if (!ends.empty())
          ends.pop();
      }
    } else {
      while (!ends.empty()) {
        ends.pop();
        ret += delta;
        //printf("timer=%d, %c, %d, %d\n", timer, ch, f->action, ret);
      }
    }

    s.pop();
  }
  return ret;

}

//unit test

int recursion_level = 0;
void unit_test(int rec_lev) {
  recursion_level = rec_lev;
  a();
  a();
}

void a() {
  _START_
  b();
  c();
  _END_
}
void b() {
  _START_
  if (0 < recursion_level--)
    b();
  else
    c();
  _END_
}
void c() {
  _START_
  _END_
}
} // namespace profiler

#endif // _PROFILER_H_
