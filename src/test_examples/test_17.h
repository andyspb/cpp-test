// tests17.h
// author: andrey.krutogolov@gmail.com
// date:   01.04.2013

#ifndef TESTS17_H_
#define TESTS17_H_

namespace test_17 {

class Base {
 public:
  int m_nPublic;
 private:
  int m_nPrivate;
 protected:
  int m_nProtected;
};

class Pri : private Base {
  // Private inheritance means:
  // m_nPublic becomes private
  // m_nPrivate stays private
  // m_nProtected becomes private
 public:
  Pri() {
    // The derived class always uses the immediate parent's class access specifications
    // Thus, Pub uses Base's access specifiers
    m_nPublic = 1;  // okay: anybody can access public members
    //  m_nPrivate = 2;  // not okay: derived classes can't access private members in the base class!
    m_nProtected = 3;  // okay: derived classes can access protected members
  }
};

TEST_RESULT main() {
  LOG(INFO) << __PRETTY_FUNCTION__;

  // Outside access uses the access specifiers of the class being accessed.
  // Note that because Pri has inherited privately from Base,
  // all members of Base have become private when access through Pri.
  Pri cPri;
//  cPri.m_nPublic = 1;  // not okay: m_nPublic is now a private member when accessed through Pri
//  cPri.m_nPrivate = 2;  // not okay: can not access private members from outside class
//  cPri.m_nProtected = 3;  // not okay: m_nProtected is now a private member when accessed through Pri

  // However, we can still access Base members as normal through Base:
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
  Base cBase;
  cBase.m_nPublic = 1;  // okay, m_nPublic is public
//  cBase.m_nPrivate = 2;  // not okay, m_nPrivate is private
//  cBase.m_nProtected = 3;  // not okay, m_nProtected is protected

  RETURN_OK();
}

}  // namespace tests17

#endif  // TESTS17_H_
