/*
 * parser.h
 *
 *  Created on: Oct 22, 2016
 *      Author: andy
 */

#ifndef SRC_PARSER_PARSER_H_
#define SRC_PARSER_PARSER_H_

#include "json_parser.h"

namespace parser {

TEST_RESULT test() {
  __SCOPE_LOG__;

  assert(json_parser::test());

  RETURN_OK();
}

}  // namespace parser

#endif /* SRC_PARSER_PARSER_H_ */
