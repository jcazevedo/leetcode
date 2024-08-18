// 264. Ugly Number II
// https://leetcode.com/problems/ugly-number-ii/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int nthUglyNumber(int n) {
    vector<int> nums(n);
    nums[0] = 1;
    int idx2 = 0, idx3 = 0, idx5 = 0, next2 = 2, next3 = 3, next5 = 5;
    for (int i = 1; i < n; ++i) {
      int next = min(next2, min(next3, next5));
      nums[i] = next;
      if (next == next2) {
        idx2++;
        next2 = nums[idx2] * 2;
      }
      if (next == next3) {
        idx3++;
        next3 = nums[idx3] * 3;
      }
      if (next == next5) {
        idx5++;
        next5 = nums[idx5] * 5;
      }
    }
    return nums[n - 1];
  }
};
