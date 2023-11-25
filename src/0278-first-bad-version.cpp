// 278. First Bad Version
// https://leetcode.com/problems/first-bad-version/

class Solution {
 private:
  bool isBadVersion(int n) {
    // This API is defined for us.
    return true;
  }

 public:
  int firstBadVersion(int n) {
    int lo = 1, hi = n;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      bool is_mid_bad = isBadVersion(mid);
      if (is_mid_bad) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }
    return lo;
  }
};
