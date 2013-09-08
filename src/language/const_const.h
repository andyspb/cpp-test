#include <iostream>
using namespace std;

namespace const_const {

class Test {
  public:
    int data;

  public:
    Test()
        : data(0) {
      cout << __FUNCTION__ << " data:" << data << endl;
    }

    int GetValue() const {
      cout << "const " << __FUNCTION__ << endl;
      return data;
    }
    int GetValue() {
      {
        cout << "non-const " << __FUNCTION__ << endl;
        return data;
      }
    }
    void test_const() const {
      cout << __FUNCTION__ << endl;
    }
    ;
    void test_noconst() const {
      cout << __FUNCTION__ << endl;
    }
    ;
};

const char *Function1() {
  return "Some text";
}

class Something {
  public:
    static int s_nValue;
};

//int Something::s_nValue = 1;

class A {
  public:
    virtual ~A() {
      cout << "from ~A" << endl;
    }
};
class B: public A {
  public:
    ~B() {
      cout << "from ~B" << endl;
    }
};

void test() {

  //char * const p = "test";

  //char * const q = "Goodbye!";

  //const int * Constant1; //declares that Constant2 is variable pointer to a constant integer and

  //int const * Constant2; //is an alternative syntax which does the same, whereas
  //int i =1;
  //int * const Constant3 = &i; //declares that Constant3 is constant pointer to a variable integer and

  //const int ci = 2;

  //int const * const Constant4 = &ci; //declares that Constant4 is constant pointer to a constant integer.
  //
  ////Basically ‘const’ applies to whatever is on its immediate left (other than if there is nothing there in which case it applies to whatever is its immediate right).

  ////Function1()[1]='a';

  //const Test ct;
  //ct.test_noconst();
  ////ct.data = 5;
  //ct.GetValue();
  //Test t;
  //t.test_const();
  //t.data = 5;
  //t.GetValue();

  A a;
  B * b = static_cast<B*>(&a);

  //    delete a;

  delete b;

  //B * bb = new B();
  //delete bb;

}

}
