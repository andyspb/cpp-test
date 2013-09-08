

#include "test.h"

#include "logger.h"
#include "string_utils.h"

#include <iostream>
#include <assert.h>

//#include "demo/demo_http_server/demo_http_server.h"
#include "update_srv/update_srv.h"


// for c++011
// -std=gnu++0x
// __GXX_EXPERIMENTAL_CXX0X__

int main(int argc, char **argv) {
//int main(int argc, char *argv[]) {
//  epee::log_space::get_set_log_detalisation_level(true, LOG_LEVEL_2);
//  epee::log_space::log_singletone::add_logger(LOGGER_CONSOLE, NULL, NULL);
//  LOG("Start tests");
//
//  demo::HttpTest::test(argc, argv);
//  omaha::backend::HttpServer::srv_test(argc, argv);
  //  using namespace epee;
//  epee::log_space::get_set_log_detalisation_level(true, LOG_LEVEL_2);
//  epee::log_space::log_singletone::add_logger(LOGGER_CONSOLE, NULL, NULL);
//
//  std::cout << "All test cases -------------------->" << std::endl;

//namespace logger = epee::logger;
//  assert(epee::logger::test());
//  assert(epee::stringer::test());

//  demo::main(0, 0);

// algoritms
//  assert(algorithms::test());

// boost tests
//  assert(boosts::test());

//cpp0x
//  assert(cpp0x::test());

// cracking code interviews
//  assert(cracking::test());

// funcions
//  assert(func::test());

// hash functions
//  assert(hashcodes::test());

// language
//  assert(language::test());

//lambda
//  assert(lambda::test());
//  templates
//  assert(templates::test());

// patterns
//  assert(patterns::test());

// quiz
//  assert(quiz::test());

  // quiz
  //  assert(quiz::test());

//  assert(smart_ptr::test());


  tests::test();

// virtuals
//  assert(virtuals::test());

// transas
//  transas_test::test();


  std::cout << "\n<-------------------- All done" << std::endl;
  return 0;
}

