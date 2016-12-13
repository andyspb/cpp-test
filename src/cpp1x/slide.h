/*
 * slide.h
 *
 *  Created on: Dec 10, 2016
 *      Author: andy
 */

#ifndef SRC_CPP1X_SLIDE_H_
#define SRC_CPP1X_SLIDE_H_

namespace slide {

template<typename It, typename randIter>
auto slide(It first, It last, randIter pivot) -> std::pair<It, It> {
  if (pivot < first)
    return {pivot, std::rotate(pivot, first, last)};
  if (last < pivot)
    return {std::rotate(first, last, pivot), pivot};
  return {first, last};
}

TEST_RESULT test() {
  __SCOPE_LOG__;

  RETURN_OK();
}

}  // namespace slide

#endif /* SRC_CPP1X_SLIDE_H_ */
