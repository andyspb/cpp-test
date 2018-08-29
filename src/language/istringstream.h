
std::string s = "1 2 3";  // this is the original string
std::istringstream is(s);  // this istringstream contains a copy of s
int i, j, k;  // variables to write to
is >> i >> j >> k;  // now i is 1, j is 2, and k is 3

