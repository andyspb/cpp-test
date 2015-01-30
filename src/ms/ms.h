#ifndef _MS_H_
#define _MS_H_

#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>


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
int intLengt(std::vector<Interval>& v) {
  // sorted by start
  std::sort(v.begin(), v.end(), IntervalLess);

  int arr[100];
  for (size_t i = 0; i < v.size(); ++i) {
    for (int j = 1; j < 100; ++i) {
      if (v[i].start >= j || v[i].end < j)
        arr[j] = 1;
    }
  }

  int count = 0;
  for (int j = 0; j < 100; ++j) {
    if (arr[j] == 1)
      ++count;
  }
  return count;
}

int intLength2(std::vector<Interval>& v) {
  // sorted by start

  std::sort(v.begin(), v.end(), IntervalLess);
  if (v.empty()) {
    return 0;
  }
  int start, end;
  int l = 0;
  std::queue<int> sq;
  for (size_t i = 0; i < v.size(); ++i) {
    int t = std::numeric_limits<int>::min();
    if (!sq.empty()) {
      t = sq.front();
    }
    start = v[i].start;
    if (start < t) {
      start = t + 1;
    }
    end = v[i].end;
    if (end > t) {
      sq.pop();
      sq.push(end);
      l += end - start;
    }
  }
  return l;
}

void printIntervals(std::vector<Interval>& v) {
  std::for_each(v.begin(), v.end(), [](Interval &i){ std::cout<< "["
    << i.start << "," << i.end << "] ";});
  std::cout<<std::endl;
}

void fillTest(std::vector<Interval>& v, Interval intervals[], size_t size) {
  if (!v.empty()) {
    v.clear();
  }
  for (size_t i = 0; i<size; ++i) {
    v.push_back(intervals[i]);
  }
}

int test() {
  std::cout<<"ms test:\n";
  //[1, 5], [2, 7] 6
  std::vector<Interval> vi;
  Interval i[] = {Interval(1, 5), Interval(2, 7)};
  fillTest(vi, vi , 2);
  //[1, 2], [5, 6] 2
  //[1, 7], [2, 6], [3, 5] 6

  std::cout<<std::endl;
  return 1;
}

}

#endif  // _MS_H_
