/*
 * copy.h
 *
 *  Created on: Sep 3, 2015
 *      Author: andy
 */

#ifndef SRC_LANGUAGE_COPY_H_
#define SRC_LANGUAGE_COPY_H_

#include <vector>
#include <algorithm>
#include <iostream>

namespace copy_ {

TEST_RESULT test() {
  __SCOPE_LOG__;

  std::vector<int> orig;
  orig.push_back(1);
  orig.push_back(2);
  orig.push_back(3);
  orig.push_back(4);
  orig.push_back(5);
  orig.push_back(6);

  std::vector<int>  dest;
  std::cout<< "orig\n";
  std::for_each(orig.begin(), orig.end(), [](int &n){std::cout<< n <<" ";});
  std::cout<<std::endl;
  std::cout<< "dest\n";
  std::for_each(dest.begin(), dest.end(), [](int &n){std::cout<< n <<" ";});
  std::cout<<std::endl;

  std::cout<< "after copy_n\n";

  std::copy_n(orig.begin(), 5, std::back_inserter(dest));
  std::cout<< "dest\n";
  std::for_each(dest.begin(), dest.end(), [](int &n){std::cout<< n <<" ";});
  std::cout<<std::endl;


  RETURN_OK();
}

}  // namespace copy_



#endif /* SRC_LANGUAGE_COPY_H_ */
