#include <stdio.h>

namespace smartptr_test {
class Person {
  char* pName;
  int age;

 public:
  Person()
      : pName(0), age(0) {
  }
  Person(char* pName, int age)
      : pName(pName), age(age) {
  }
  ~Person() {
  }

  void Display() {
    printf("Name = %s Age = %d \n", pName, age);
  }
  void Shout() {
    printf("Ooooooooooooooooo");
  }
};

template<typename T> class SP {
  private:
    T* pointee;
  public:
    SP(T * t)
        : pointee(t) {

    }
    ~SP() {
      delete pointee;
    }
    T& operator*() {
      return *pointee;
    }
    T* operator->() {
      return pointee;
    }
};

class A {
  public:
    A() {
      printf("ctor A\n");
    }
    virtual ~A() {
      printf("from ~A\n");
    }
    virtual void test() =0;
    virtual void Do() {
      printf("Do from A\n");
    }

};
void A::test() {
  printf("from A::test()\n");

}

class B: public A {
  public:
    virtual void test();

  private:
    void Do() {
      printf("Do from B\n");
    }

};
void B::test() {
  A::test();
  printf("from B::test()\n");

}

class C: public B {
  private:
    void Do() {
      printf("Do from A\n");
    }

};
void test() {
  //SP<Person> p(new Person("Scott", 25));
  //p->Display();
  // Don't need to delete Person pointer..

  A * a = new C();

  a->Do();

  delete a;
}

}
;
