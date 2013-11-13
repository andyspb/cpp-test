#ifndef _BOOST_TEST_H_
#define _BOOST_TEST_H_

#include <assert.h>
#include <iostream>

#include "boost_2.h"
#include "boost_3.h"
#include "boost_4.h"
#include "boost_5.h"
#include "boost_6.h"
#include "boost_7.h"
#include "boost_asio.h"
#include "boost_cond.h"
#include "boost_lambda.h"
#include "boost_lexical.h"
#include "boost_pc.h"
#include "boost_pc_2.h"
#include "boost_prod_cons.h"
#include "boost_shared_lock.h"
#include "boost_shared_mutex.h"
#include "boost_threads.h"

namespace boosts {
int test() {
  std::cout << "Boost tests:\n";
//    assert(boost_1::test());
  assert(boost_2::test());
//  assert(boost_3::test());
//  assert(boost_4::test());
//  assert(boost_5::test());
//  assert(boost_6::test());
//  assert(boost_7::test());
// assert(boost_asio::test());
//  assert(boost_lambda::test());
//  assert(boost_lexical::test());
//  assert(boost_pc::test());
//  assert(boost_prod_cons::test());

  std::endl(std::cout);
  return 1;
}

}  // boosts

#endif  // _BOOST_TEST_H_
