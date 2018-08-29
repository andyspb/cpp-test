/*
 * cpp0x_move.h
 *
 *  Created on: 26 ���� 2015 �.
 *      Author: andy
 */

#ifndef SRC_CPP1X_CPP0X_MOVE_H_
#define SRC_CPP1X_CPP0X_MOVE_H_

namespace move {

class Base {
 public:
  Base(int val)
      : v(val),
        ref(v),
        pv(new int(10)) {
    LOG(INFO) << "constructor Base";
  }

  virtual ~Base() {
    LOG(INFO) << "destructor ~Base";
  }

  int v;
  int& ref;
  int* pv;

//  Base(const Base&& b) : v(b.v), ref(b.ref), pv(b.pv){
//    LOG(INFO) << " move constructor Base()";
//  };
  Base(Base&&) = default;

  Base(const Base&) = delete;
  void operator=(const Base&) = delete;

};

TEST_RESULT test() {
  __SCOPE_LOG__;

  Base b(5);
  LOG(INFO) << "b.v=" << b.v << " b.ref=" << b.ref << " b.pv=" << b.pv;

  Base b1(std::move(b));

  LOG(INFO) << "b1.v=" << b1.v << " b1.ref=" << b1.ref << " b1.pv=" << b1.pv;

  LOG(INFO) << "b.v=" << b.v << " b.ref=" << b.ref << " b.pv=" << b.pv;

  int n = 3;
  int&& rv = 3;

  LOG(INFO) << "n=" << n << " rv=" << rv << "\n";

  int v2 = ::std::move(rv);

  LOG(INFO) << "v2=" << v2 << " rv=" << rv << "\n";

  RETURN_OK();
}

}  // namespace cpp1x_move

#endif /* SRC_CPP1X_CPP1X_MOVE_H_ */
