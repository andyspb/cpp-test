/*
 * merge_overlapping_itnervals.h
 *
 *  Created on: 30 ���. 2015 �.
 *      Author: andy
 */

#ifndef MERGE_OVERLAPPING_ITNERVALS_H_
#define MERGE_OVERLAPPING_ITNERVALS_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

namespace merge_overlapping_itnervals {

// An interval has start time and end time
struct Interval {
  int start;
  int end;
};

// Compares two intervals according to their staring time.
// This is needed for sorting the intervals using library
// function std::sort(). See http://goo.gl/iGspV
bool compareInterval(Interval i1, Interval i2) {
  return (i1.start < i2.start) ? true : false;
}

// The main function that takes a set of intervals, merges
// overlapping intervals and prints the result
void mergeIntervals(vector<Interval>& intervals) {
  // Test if the given set has at least one interval
  if (intervals.size() <= 0)
    return;

  // Create an empty stack of intervals
  stack<Interval> s;

  // sort the intervals based on start time
  sort(intervals.begin(), intervals.end(), compareInterval);

  // push the first interval to stack
  s.push(intervals[0]);

  // Start from the next interval and merge if necessary
  for (size_t i = 1; i < intervals.size(); ++i) {
    // get interval from stack top
    Interval top = s.top();

    // if current interval is not overlapping with stack top,
    // push it to the stack
    if (top.end < intervals[i].start) {
      s.push(intervals[i]);
    }
    // Otherwise update the ending time of top if ending of current
    // interval is more
    else if (top.end < intervals[i].end) {
      top.end = intervals[i].end;
      s.pop();
      s.push(top);
    }
  }

  // Print contents of stack
  cout << "\n The Merged Intervals are: ";
  while (!s.empty()) {
    Interval t = s.top();
    cout << "[" << t.start << "," << t.end << "]" << " ";
    s.pop();
  }

  return;
}

// Functions to run test cases
void TestCase1() {
  // Create a set of intervals
  Interval intvls[] = { { 6, 8 }, { 1, 9 }, { 2, 4 }, { 4, 7 } };
  vector<Interval> intervals(intvls, intvls + 4);

  // Merge overlapping inervals and print result
  mergeIntervals(intervals);
}
void TestCase2() {
  // Create a set of intervals
  Interval intvls[] = { { 6, 8 }, { 1, 3 }, { 2, 4 }, { 4, 7 } };
  vector<Interval> intervals(intvls, intvls + 4);

  // Merge overlapping inervals and print result
  mergeIntervals(intervals);
}
void TestCase3() {
  // Create a set of intervals
  Interval intvls[] = { { 1, 3 }, { 7, 9 }, { 4, 6 }, { 10, 13 } };
  vector<Interval> intervals(intvls, intvls + 4);

  // Merge overlapping inervals and print result
  mergeIntervals(intervals);
}

// Driver program to test above functions
int test() {
  TestCase1();
  TestCase2();
  TestCase3();
  return 1;
}

}

#endif /* MERGE_OVERLAPPING_ITNERVALS_H_ */
