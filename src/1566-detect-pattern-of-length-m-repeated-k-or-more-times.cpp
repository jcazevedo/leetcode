// 1566. Detect Pattern of Length M Repeated K or More Times
// https://leetcode.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times/

#include <vector>

using namespace std;

class Solution {
 public:
  bool containsPattern(vector<int>& arr, int m, int k) {
    int n = arr.size();
    for (int i = 0; i + m <= n; ++i) {
      int cnt = 1;
      int j = i + m;
      bool good = true;
      while (j < n) {
        int it = i, k = j;
        for (k = j; k < n && k < j + m && good; ++k, ++it) {
          if (arr[k] != arr[it]) { break; }
        }
        if (k != j + m) { break; }
        j += m;
        ++cnt;
      }
      if (cnt >= k) { return true; }
    }
    return false;
  }
};
