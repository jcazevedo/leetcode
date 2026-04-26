// 2926. Maximum Balanced Subsequence Sum
// https://leetcode.com/problems/maximum-balanced-subsequence-sum/

#include <algorithm>
#include <vector>

using namespace std;

class FenwickTree {
 private:
  vector<long long> bits;
  int l;

 public:
  FenwickTree(int n) {
    l = n;
    bits.assign(n + 1, 0);
  }

  void update(int i, long long v) {
    while (i <= l) {
      if (v > bits[i]) { bits[i] = v; }
      i += (i & (-i));
    }
  }

  long long find(int i) {
    long long ans = 0;
    while (i > 0) {
      if (bits[i] > ans) { ans = bits[i]; }
      i -= (i & (-i));
    }
    return ans;
  }
};

class Solution {
 public:
  long long maxBalancedSubsequenceSum(vector<int>& nums) {
    int n = nums.size();
    vector<long long> keys(n);
    for (int i = 0; i < n; ++i) { keys[i] = nums[i] - i; }
    vector<long long> sorted = keys;
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    int m = sorted.size();
    FenwickTree bit(m);
    long long ans = nums[0];
    for (int i = 0; i < n; ++i) {
      int rank = lower_bound(sorted.begin(), sorted.end(), keys[i]) - sorted.begin() + 1;
      long long dp = bit.find(rank) + nums[i];
      if (dp > ans) { ans = dp; }
      if (dp > 0) { bit.update(rank, dp); }
    }
    return ans;
  }
};
