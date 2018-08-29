/*
 * find_sum_overlapping_intervals.h
 *
 *  Created on: 30 ���. 2015 �.
 *      Author: andy
 */

#ifndef FIND_SUM_OVERLAPPING_INTERVALS_H_
#define FIND_SUM_OVERLAPPING_INTERVALS_H_

#include <algorithm>
#include <iostream>
#include <stack>

namespace find_sum_overlapping_intervals {

struct Interval {
  Interval(int s, int e)
      : start(s),
        end(e) {
  }
  ;
  int start;
  int end;
  int getLength() {
    if (end <= start) {
      return 0;
    }
    return (end - start - 1);
  }
};

struct {
  bool operator()(Interval a, Interval b) {
    return a.start < b.start;
  }
} IntervalLess;

void printIntervals(std::vector<Interval>& v) {
  std::for_each(v.begin(), v.end(), [](Interval &i) {std::cout<< "["
    << i.start << "," << i.end << "] ";});
  std::cout << std::endl;
}

int find_sum_of_intervals_with_stack(std::vector<Interval>& vector_intervals) {
  if (vector_intervals.empty()) {
    return 0;
  }
  std::sort(vector_intervals.begin(), vector_intervals.end(), IntervalLess);
  printIntervals(vector_intervals);

//  int start(0), end(0);
  int l = 0;
  std::stack<Interval> stack;
  stack.push(vector_intervals[0]);
  for (size_t i = 0; i < vector_intervals.size(); ++i) {
    Interval top = stack.top();
    if (top.end < vector_intervals[i].start) {
      stack.push(vector_intervals[i]);
    } else if (top.end < vector_intervals[i].end) {
      top.end = vector_intervals[i].end;
      stack.pop();
      stack.push(top);
    }
  }
  // Print contents of stack
  std::cout << "\n The Merged Intervals are: ";
  while (!stack.empty()) {
    Interval t = stack.top();
    std::cout << "[" << t.start << "," << t.end << "]" << " ";
    stack.pop();
    l += t.end - t.start;
  }

  return l;
}

}  // namespace find_sum_overlapping_intervals

#endif /* FIND_SUM_OVERLAPPING_INTERVALS_H_ */
