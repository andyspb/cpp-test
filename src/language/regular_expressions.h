/*
 * regular_expressions.h
 *
 *  Created on: 21 џэт. 2017 у.
 *      Author: andy
 */

#ifndef SRC_LANGUAGE_REGULAR_EXPRESSIONS_H_
#define SRC_LANGUAGE_REGULAR_EXPRESSIONS_H_
#include <iostream>
#include <iterator>
#include <string>
#include <regex>

namespace regular_expressions {

TEST_RESULT test() {
  __SCOPE_LOG__;
  std::string s = "Some people, when confronted with a problem, think "
      "\"I know, I'll use regular expressions.\" "
      "Now they have two problems.";
  std::cout << '\t' << s << '\n';

  std::regex self_regex(
      "REGULAR EXPRESSIONS",
      std::regex_constants::ECMAScript | std::regex_constants::icase);

  if (std::regex_search(s, self_regex)) {
    LOG(INFO) << "Text contains the phrase 'regular expressions'\n";
  }

  //std::regex word_regex("(\\S+)");
  std::regex word_regex("(\\s)");
  auto words_begin = std::sregex_iterator(s.begin(), s.end(), word_regex);
  auto words_end = std::sregex_iterator();

  std::cout << "Found " << std::distance(words_begin, words_end) << " words\n";

  const int N = 6;
  std::cout << "Words longer than " << N << " characters:\n";
  for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
    std::smatch match = *i;
    std::string match_str = match.str();
    if (match_str.size() > N) {
      std::cout << "  " << match_str << '\n';
    }
  }

  //std::regex long_word_regex("(\\w{7,})");
  //std::string new_s = std::regex_replace(s, long_word_regex, "[$&]");

  std::regex long_word_regex("(\\s)");
  std::string new_s = std::regex_replace(s, long_word_regex, "_");


  std::cout << new_s << '\n';

  RETURN_OK();
}
}  // namespace regular_expressions

#endif /* SRC_LANGUAGE_REGULAR_EXPRESSIONS_H_ */
