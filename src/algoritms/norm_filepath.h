/*
 * norm_filepath.h
 *
 *  Created on: Feb 12, 2016
 *      Author: andy
 */

#ifndef SRC_ALGORITMS_NORM_FILEPATH_H_
#define SRC_ALGORITMS_NORM_FILEPATH_H_

namespace norm_filepath {

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;
  std::string sample1 = "/a/b/c";
  std::string sample2 = "/a/b/../c";
  std::string sample3 = "/a/b/c/../";
  std::string sample4 = "/a/b/c../../";
  std::string sample5 = "/a/b/../c../";
  std::string sample6 = "/a/b/../c../";

  RETURN_OK();
}
}  // namespace norm_filepath

#endif /* SRC_ALGORITMS_NORM_FILEPATH_H_ */
