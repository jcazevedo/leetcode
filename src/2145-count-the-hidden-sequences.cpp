// 2145. Count the Hidden Sequences
// https://leetcode.com/problems/count-the-hidden-sequences/

#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

class Solution {
 public:
  int numberOfArrays(vector<int>& differences, int lower, int upper) {
    long long lo = 0, hi = 0, curr = 0;
    for (int diff : differences) {
      curr += diff;
      lo = min(lo, curr);
      hi = max(hi, curr);
    }
    if (hi - lo > upper - lower) { return 0; }
    return (upper - lower) - (hi - lo) + 1;
  }
};
