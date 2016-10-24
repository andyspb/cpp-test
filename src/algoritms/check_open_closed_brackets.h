/*
 * check_open_closed_brackets.h
 *
 *  Created on: 24 ���. 2015 �.
 *      Author: andy
 */

#ifndef CHECK_OPEN_CLOSED_BRACKETS_H_
#define CHECK_OPEN_CLOSED_BRACKETS_H_

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stack>
#include <string>

namespace check_open_closed_brackets {

typedef ::std::stack<char> Brackets;

constexpr char open_brackets[] = {'(', '['};
constexpr ::std::map<char, char> closing = {{'(', ')'}, {'[', ']'}};

void pushOpeningBrackets(Brackets& opening, char bracket) {
  for (char open_bracket : open_brackets) {
    if (bracket == open_bracket)
      opening.push(open_bracket);
  }
}

bool errorsFound(Brackets& stack, char openingBracket, char closingBracket)
{
    if(stack.empty())
    {
        ::std::cout << "Unmatched " << closingBracket;
        return true;
    }

    char topBracket = stack.top();
    stack.pop();

    if(topBracket != openingBracket) {
        auto expectedClosing = closing.find(topBracket);
        std::cout << "Expected " << expectedClosing->second << " but found "
                  << closingBracket << std::endl;
        return true;
    }

    return false;
}
bool CheckBracketsMatching() {
  std::string input_str;
  std::getline(std::cin, input_str);

  Brackets brackets;

  for (char ch : input_str) {
    pushOpeningBrackets(brackets, ch);

    if (ch == ')') {
      if (errorsFound(brackets, '(', ')')) {
        return false;
      }
    } else if (ch == ']') {
      if (errorsFound(brackets, '[', ']')) {
        return false;
      }
    }
  }

  // checks for missing bracket or full match
  if (!brackets.empty()) {
    char topBracket = brackets.top();
    brackets.pop();

    if ('(' == topBracket) {
      std::cerr << "Missing )";
      return false;
    }
    else if ('[' == topBracket) {
      std::cerr << "Missing ]";
      return false;
    }
  } else {
    std::cout << "All brackets match!";
    return true;
  }
}

}  // namespace check_open_closed_brackets

#endif /* CHECK_OPEN_CLOSED_BRACKETS_H_ */
