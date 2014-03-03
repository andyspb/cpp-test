#include "test.h"

#include <iostream>
#include <assert.h>

int main(int argc, char **argv) {
  std::cout << "All test cases -------------------->" << std::endl;

//  assert(algorithms::test());
//  assert(cpp0x::test());
//  assert(cracking::test());
    assert(exceptions::test());
//  assert(facebook::test());
//  assert(func::test());
//  assert(hashcodes::test());
//  assert(lambda::test());
//  assert(language::test());
//  assert(templates::test());
//  assert(patterns::test());
//  assert(quiz::test());
//  assert(smart_ptr::test());
//  assert(tests::test());
//  assert(virtuals::test());
  std::cout << "\n<-------------------- All done" << std::endl;
  return 0;

}

