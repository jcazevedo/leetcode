// 1802. Maximum Value at a Given Index in a Bounded Array
// https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/

#include <iostream>

using namespace std;

class Solution {
private:
  long long sumTo(long long n) { return n * (n + 1) / 2; }

  long long totSumFor(int n, int index, int value) {
    long long sumLeft = sumTo(value);
    if (value > index + 1)
      sumLeft -= sumTo(value - index - 1);
    long long sumRight = sumTo(value - 1);
    if (value > n - index)
      sumRight -= sumTo(value - n + index);
    return sumLeft + sumRight;
  }

public:
  int maxValue(int n, int index, int maxSum) {
    int lo = 0, hi = maxSum - n;
    while (lo < hi) {
      int mid = lo + (hi - lo + 1) / 2;
      if (totSumFor(n, index, mid) > maxSum - n)
        hi = mid - 1;
      else
        lo = mid;
    }
    return lo + 1;
  }
};
