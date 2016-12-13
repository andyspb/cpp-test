namespace db_test {
#include <iostream>
//template<class T> class Array
//{
//private:
//    T* p;
//    size_t size;
//public:
//    Array (size_t n) : size(n)
//    {
//        T* p = new T[n];
//    }
//    Array(const Array& arr)
//    {
//        size = arr.size;
//        p = new T[size];
//        memcpy(p, arr);
//    }

//    Array& operator=(const Array& arr)
//    {
//        size = arr.size;
//        p = new T[size];
//        memcpy(p, arr);
//        return *this;
//    }

//    virtual ~Array ()
//    {
//        delete[] p;
//    }

//    T& operator[] (size_t i)
//    {
//        return p[i];
//    }
//    T& at(size_t i)
//    {
//        if(i<size)
//            return p[i];
//        throw Exception("out of border")
//    }
//    void clear()
//    {
//        size = 0;
//        delete[] p;
//    }
//    size_t length()
//    {
//        return size;
//    }

//};

//template<>
//class Array<int>
//{
//    Array (size_t n): size(n)
//    {
//        int* p = new int[n];
//        std::_Bool<<"Array<int> partial specialization"<<std::endl;
//    }
//};
//template<int n> struct PrintN
//{
//    PrintN()
//    {
//        cout<<n<<' ';
//        PrintN<n-1> n_1;
//    }
//};
//template<> struct PrintN<0>
//{
//    PrintN()
//    {
//        cout<<endl;
//    }
//};
//int main()
//{
//    PrintN<10> pn;
//    return 0;
//}
//class Base
//{
//public:
//    Base(int x)
//        : b(x), a(b-2), c(0)
//    {
//        cout<<"test2"<<endl;
//        std::cout << "a " << a
//            << ",b " << b
//            << ",c " << c
//            << endl;
//    }
//
//private:
//    int a;
//    int b;
//    int c;
//};
//int main()
//{
//    Base temp(2);
//    return 0;
//}

//class Base
//{
//public:
//    Base():a(0)
//    {
//        cout << method(a++);
//    }
//
//    ~Base()
//    {
//        cout << method(a++);
//    }
//
//    virtual int method(int val)
//    {
//        return val + 1;
//    }
//
//protected:
//    int a;
//};
//
//class Derived : public Base
//{
//public:
//    Derived():Base()
//    {
//        cout << method(2);
//    }
//
//    ~Derived()
//    {
//        cout << method(3);
//    }
//
//    virtual int method(int val)
//    {
//        return val - 1;
//    }
//};
//
//int main()
//{
//    auto_ptr<Base> obj( new Derived );
//    return 0;
//}

//#include <stdio.h>
//class A
//{
//public:
//    A() { puts("A();"); }
//    ~A() { puts("~A();"); }
//};
//
//class B : public A
//{
//public:
//    B() { puts("B();"); }
//    ~B() { puts("~B();"); }
//};
//
//void func( A a )
//{
//}
//
//void main()
//{
//    B b;
//    func(b);
//}

//const int i = 8;
//
//int main(/*int argc, char* argv[] */)
//{
//    const_cast<int&>(i) = 7;
//    return 0;
//}

class Base {
  public:
    Base()
        : a(0) {
      std::cout << method(a++);
    }

    virtual ~Base() {
      std::cout << "Base\n";
      std::cout << method(a++);
    }

    virtual int method(int val) {
      return val + 1;
    }

  protected:
    int a;
};

class Derived: public Base {
  public:
    Derived()
        : Base() {
      std::cout << method(2);
    }

    virtual ~Derived() {
      std::cout << "Derived\n";
      std::cout << method(3);
    }

    virtual int method(int val) {
      return val - 1;
    }
};

int main() {
  std::auto_ptr<Base> obj(new Derived);
  return 0;
}

//class String
//{
//public:
//    String(const char* str)
//    {
//        myStr = new char[strlen(str)+1];
//        strcpy(myStr, str);
//    }
//
//    String(const String& s)
//    {
//        myStr = new char[strlen(s.str())+1];
//        strcpy(myStr, s.str());
//    }
//
//    ~String()
//    {
//        delete[] myStr;
//    }
//
//    const char* str() const
//    {
//        return myStr;
//    }
//
//protected:
//    char* myStr;
//};
//void printout(String& param)
//{
//    std::cout << param.str()<< std::endl;
//}
//
//int main(/*int argc, char* argv[]*/)
//{
//    String a("hello");
//    String b=a;
//
//    printout(a);
//    printout(b);
//
//    return 0;
//}

//template < typename T > class SmartPointer
//{
//private:
//    T* pointee;
//public:
//    SmartPointer(T * t):pointee(t)
//    {
//
//    }
//    ~SmartPointer()
//    {
//        delete pointee;
//    }
//    T& operator*()
//    {
//        return *pointee;
//    }
//    T* operator->()
//    {
//        return pointee;
//    }
}
;

