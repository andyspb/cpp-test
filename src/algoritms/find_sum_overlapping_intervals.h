/*
 * find_sum_overlapping_intervals.h
 *
 *  Created on: 30 џэт. 2015 у.
 *      Author: andy
 */

#ifndef FIND_SUM_OVERLAPPING_INTERVALS_H_
#define FIND_SUM_OVERLAPPING_INTERVALS_H_

namespace find_sum_overlapping_intervals {

struct Interval {
  int start;
  int end;
};
int find_sum_of_intervals_with_stack(std::vector<Interval>& vector_intervals) {
  if (vector_intervals.empty()) {
    return 0;
  }
  std::sort(vector_intervals.begin(), vector_intervals.end(), IntervalLess);

  int start(0), end(0);
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
    cout << "[" << t.start << "," << t.end << "]" << " ";
    stack.pop();
    l += t.end - t.start;
  }

  return l;
}

}  // namespace find_sum_overlapping_intervals



#endif /* FIND_SUM_OVERLAPPING_INTERVALS_H_ */
