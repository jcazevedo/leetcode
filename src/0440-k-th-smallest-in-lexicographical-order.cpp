// 440. K-th Smallest in Lexicographical Order
// https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/

#include <algorithm>

using namespace std;

class Solution {
 private:
  int steps(long long n, long long left, long long right) {
    int steps = 0;
    while (left <= n) {
      steps += min(n + 1, right) - left;
      left *= 10;
      right *= 10;
    }
    return steps;
  }

 public:
  int findKthNumber(int n, int k) {
    int curr = 1;
    k--;
    while (k > 0) {
      int cnt = steps(n, curr, curr + 1);
      if (cnt <= k) {
        ++curr;
        k -= cnt;
      } else {
        curr *= 10;
        --k;
      }
    }
    return curr;
  }
};
