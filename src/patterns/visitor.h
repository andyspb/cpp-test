#ifndef _VISITOR_H_
#define _VISITOR_H_

#include <iostream>

namespace visitor {
using namespace std;

struct Visitor;
// forward declaration (step 2)

struct Element {
    virtual ~Element() {
    }
    virtual void accept(Visitor*) = 0;  // step 2
};

struct Foo: public Element {
    void make_foo() {
      cout << "Making some Foo..." << endl;
    }
    virtual void accept(Visitor*);  // step 2
};

struct Bar: public Element {
    void make_bar() {
      cout << "Making some Bar..." << endl;
    }
    virtual void accept(Visitor*);  // step 2
};

struct Baz: public Element {
    void make_baz() {
      cout << "Making some Baz..." << endl;
    }
    virtual void accept(Visitor*);  // step 2
};

// Visitor classes (step 1)
struct Visitor {
    virtual ~Visitor() {
    }
    virtual void visit(Foo*) = 0;
    virtual void visit(Bar*) = 0;
    virtual void visit(Baz*) = 0;
};

struct MakeVisitor: public Visitor {
    virtual void visit(Foo* foo) {
      foo->make_foo();
    }
    virtual void visit(Bar* bar) {
      bar->make_bar();
    }
    virtual void visit(Baz* baz) {
      baz->make_baz();
    }
};

struct CountVisitor: public Visitor {
    CountVisitor()
        : foo_count(0), bar_count(0), baz_count(0) {
    }
    void print_counters() {
      cout << "Counters: Foo(" << foo_count << ") Bar(" << bar_count << ") Baz("
          << baz_count << ")" << endl;
    }

    virtual void visit(Foo*) {
      ++foo_count;
    }
    virtual void visit(Bar*) {
      ++bar_count;
    }
    virtual void visit(Baz*) {
      ++baz_count;
    }
  private:
    int foo_count, bar_count, baz_count;
};

// Implementing the accept(Visitor*) methods (step 2)
// This has to come after the definition of the Visitor base class.
void Foo::accept(Visitor* v) {
  v->visit(this);
}
void Bar::accept(Visitor* v) {
  v->visit(this);
}
void Baz::accept(Visitor* v) {
  v->visit(this);
}

//The Element hierarchy with the visitors could be used like this:
int test() {
  std::cout << "Test: Visitor pattern example --->" << std::endl;
  list<Element*> e;
  list<Visitor*> v;
  typedef list<Element*>::const_iterator e_list_iterator;
  typedef list<Visitor*>::const_iterator v_list_iterator;

  e.push_back(new Foo);
  e.push_back(new Foo);
  e.push_back(new Bar);
  e.push_back(new Baz);

  CountVisitor* cv = new CountVisitor;
  v.push_back(cv);
  v.push_back(new MakeVisitor);

  for (e_list_iterator i = e.begin(); i != e.end(); ++i)
    for (v_list_iterator j = v.begin(); j != v.end(); ++j)
      (*i)->accept(*j);  // double dispatch

  cv->print_counters();

  for (e_list_iterator i = e.begin(); i != e.end(); ++i)
    delete *i;
  for (v_list_iterator j = v.begin(); j != v.end(); ++j)
    delete *j;
  std::cout << "<--- test passed" << std::endl;
  return 1;
}
} // namespace visitor

#endif  // _VISITOR_H_

