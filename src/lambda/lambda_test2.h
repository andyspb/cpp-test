//  lambda_test2.h
//  author: andrey.krutogolov@gmail.com
//  date:   22.02.2013

#ifndef LAMBDA_TEST2_H_
#define LAMBDA_TEST2_H_

#include <string>
#include <vector>

namespace lambda_test2 {

class AddressBook {
  public:
    // using a template allows us to ignore the differences between functors,
    // function pointers and lambda
    template<typename Func>
    std::vector<std::string> findMatchingAddresses(Func func) {
      std::vector<std::string> results;
      for (auto itr = _addresses.begin(), end = _addresses.end(); itr != end;
          ++itr) {
        // call the function passed into findMatchingAddresses and see if it matches
        if (func(*itr)) {
          results.push_back(*itr);
        }
      }
      return results;
    }

  private:
    std::vector<std::string> _addresses;
};

AddressBook global_address_book;

std::vector<string> findAddressesFromOrgs()
{
  return global_address_book.findMatchingAddresses(
      // we're declaring a lambda here; the [] signals the start
      [] (const string& addr) {return addr.find( ".org" ) != string::npos;}
      );
}
int test() {

  return 1;
}
}

#endif  // LAMBDA_TEST2_H_
