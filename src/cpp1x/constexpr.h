/*
 * cpp1x_constexpr.h
 *
 *  Created on: Jul 29, 2015
 *      Author: andy
 */

#ifndef SRC_CPP1X_CONSTEXPR_H_
#define SRC_CPP1X_CONSTEXPR_H_

namespace constexpr_ {

// literal class
class conststr {
  const char * p;
  std::size_t sz;
 public:
  template<std::size_t N>
  constexpr conststr(const char (&a)[N])
      : p(a),
        sz(N - 1) {
  }
  // constexpr functions signal errors by throwing exceptions
  // in C++11, they must do so from the conditional operator ?:
  constexpr char operator[](std::size_t n) const {
    return n < sz ? p[n] : throw std::out_of_range("");
  }
  constexpr std::size_t size() const {
    return sz;
  }
};

// C++11 constexpr functions had to put everything in a single return statement
// (C++14 doesn't have that requirement)
constexpr std::size_t countlower(conststr s, std::size_t n = 0, std::size_t c =
                                     0) {
  return
      n == s.size() ? c :
      s[n] >= 'a' && s[n] <= 'z' ?
          countlower(s, n + 1, c + 1) : countlower(s, n + 1, c);
}

// output function that requires a compile-time constant, for testing
template<int n> struct constN {
  constN() {
    std::cout << n << '\n';
  }
};

TEST_RESULT test() {
  __SCOPE_LOG__;

//  std::cout << "Number of lowercase letters in \"Hello, world!\" is ";
//  constN<countlower("Hello, world!")> out2;  // implicitly converted to conststr

//  constexpr auto x = "(4^2-9)/8+2/3"_solve;
//  std::cout << "Answer is " << x;

  int* p = NULL;
  LOG(INFO) << "p=" << p;

  RETURN_OK();
}

}  // namespace cpp1x_constexpr

#endif /* SRC_CPP1X_CONSTEXPR_H_ */
