#ifndef _MS_H_
#define _MS_H_

#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
#include <stack>

//n [a_i, b_i]
//
//[1, 5] 4
//[1, 5], [2, 7] 6
//[1, 2], [5, 6] 2
//[1, 7], [2, 6], [3, 5]
//[-2, -1]
//[1, 3], [5, 7]
//[1, 3], [1, 7], [1, 5]
//[1,3]
//[2,4]

namespace ms {

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

void fillTest(std::vector<Interval>& v, Interval intervals[], size_t size) {
  if (!v.empty()) {
    v.clear();
  }
  for (size_t i = 0; i < size; ++i) {
    v.push_back(intervals[i]);
  }
}

int find_sum_of_intervals_with_array(std::vector<Interval>& vector_intervals) {
  if (vector_intervals.empty()) {
    return 0;
  }
  std::sort(vector_intervals.begin(), vector_intervals.end(), IntervalLess);
  printIntervals(vector_intervals);

  int arr[100] = { 0 };
  for (size_t i = 0; i < vector_intervals.size(); ++i) {
    std::cout << "i=" << i << " v[" << i << "].start="
              << vector_intervals[i].start << " v[" << i << "].end="
              << vector_intervals[i].end << "\n";
    for (int j = 0; j < 100; ++j) {
      if (!(vector_intervals[i].start > j || vector_intervals[i].end <= j)) {
        std::cout << " found:" << j;
        arr[j] = 1;
      }
    }
    std::cout << std::endl;
  }

  int count = 0;
  for (int j = 0; j < 100; ++j) {
    if (arr[j] == 1)
      ++count;
  }
  return count;
}

int find_sum_of_intervals_with_stack(std::vector<Interval>& vector_intervals) {
  if (vector_intervals.empty()) {
    return 0;
  }
  std::sort(vector_intervals.begin(), vector_intervals.end(), IntervalLess);
  printIntervals(vector_intervals);

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
    std::cout << "[" << t.start << "," << t.end << "]" << " ";
    stack.pop();
    l += t.end - t.start;
  }

  return l;
}

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__ << "ms test";

  //[1, 5], [2, 7] 6
  Interval intervals_1[] = { Interval(2, 7), Interval(1, 5) };
  //[1, 2], [5, 6] 2
  Interval intervals_2[] = { Interval(1, 2), Interval(5, 6) };
  //[1, 7], [2, 6], [3, 5] 6
  Interval intervals_3[] = { Interval(3, 5), Interval(1, 7), Interval(2, 6) };

  std::vector<Interval> vec;
  fillTest(vec, intervals_1, 2);
  std::cout << find_sum_of_intervals_with_array(vec) << std::endl;
  std::cout << find_sum_of_intervals_with_stack(vec) << std::endl;
//
  fillTest(vec, intervals_2, 2);
  std::cout << find_sum_of_intervals_with_array(vec) << std::endl;
  std::cout << find_sum_of_intervals_with_stack(vec) << std::endl;

  fillTest(vec, intervals_3, 3);
//  std::cout << find_sum_of_intervals_with_array(vec) << std::endl;
//  std::cout << intLength2(vec) << std::endl;
  std::cout << find_sum_of_intervals_with_stack(vec) << std::endl;

  std::cout << std::endl;
  RETURN_OK();
}

}

#endif  // _MS_H_
