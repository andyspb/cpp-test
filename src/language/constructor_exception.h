#ifndef CONSTRUCTOR_EXCEPTION_H_
#define CONSTRUCTOR_EXCEPTION_H_

#include <iostream>
#include <exception>

namespace constructor_exception {

class Base {
	public:
		Base()
		try
				: a(0), b(0) {
			std::cout << "From Base::Base()" << std::endl;
		}
		catch (...) {

		}
		~Base() {
			std::cout << "From Base::~Base()" << std::endl;
		}

		int a;
		int b;
};

class Base1 {
	public:
		virtual ~Base1() {
			std::cout << "From Base1::~Base1()" << std::endl;
		}
};

class Derived: public Base1 {
	public:
		Derived() throw() {
			throw std::exception();
		}
		~Derived() {
			std::cout << "From Derived::~Derived()" << std::endl;
		}
};

int test() {
	std::cout << "Test: exception in constructor initializer list --->"
			<< std::endl;
	Base base;
	std::cout << "Test: exception in derived constructor --->" << std::endl;
	Derived* derived = NULL;
//	try {
		derived = new Derived();
//	} catch (...) {
//		std::cout << "From catch() " << std::endl;
//	}
	if (derived) {
		delete derived;
	}
	return 1;
}
} // namespace constructor_exception

#endif /* CONSTRUCTOR_EXCEPTION_H_ */
