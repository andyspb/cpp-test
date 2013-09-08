#include <iostream>
using namespace std;
template <class T>
bool ansisupported (T x) { return true; }

int ansisupported_test()
{
	if (ansisupported(0)) cout << "ANSI OK"<<endl;
	return 0;
}