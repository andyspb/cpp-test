n, [a_i, b_i]

[1, 5] 4
[1, 5], [2, 7] 6
[1, 2], [5, 6] 2
[1, 7], [2, 6], [3, 5]


[-2, -1]

[1, 3], [5, 7]

[1, 3], [1, 7], [1, 5]


int intLengt(vector<intevals>& v) {
    // sorted by start
    int arr[100] ;
    for (i in v ) {
       for (int j = 1; j <100; ++i  ) {
           if (v.start >= j || v.end < j)
               arr[j] = 1;
       }
    }

    int count = 0;
       for (int j = 1; j <100; ++i  ) {
          if ( arr[j] == 1 )
          ++count;
       }
    return count;
}

int intLength(vector<intevals>& v) {
    // sorted by start
    if (v.empty()) {
        return 0;
    }
    int start,end;
    int l = 0
    que<int> sq;
    for_each (i in v) {
      int t=MIN_INT;
      if (!sq.empty() ) {
         t = sq.top();
      }
      start = v.start;
      if (start<t) {
         start = t+1;
      }
      end = v.end;
      if (end >t) {
          sq.pop();
          sq.push(end);
          l += end-start;
      }
    }
    return l;
}

    [1,3]
    [2,4]

is overLaping(i1, i2)

int overLap(i1, i2) {
  if (i1.end > i2.start) {
      return (i2.start-i1.end)
  }
  return 0;
}
