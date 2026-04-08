// 3653. XOR After Range Multiplication Queries I
// https://leetcode.com/problems/xor-after-range-multiplication-queries-i/

#include <vector>

using namespace std;

class Solution {
 public:
  int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
    long long MOD = 1e9 + 7;
    int n = nums.size();
    vector<long long> a(n);
    for (int i = 0; i < n; i++) { a[i] = nums[i]; }
    for (const vector<int>& q : queries) {
      int l = q[0], r = q[1], k = q[2], v = q[3];
      for (int idx = l; idx <= r; idx += k) { a[idx] = (a[idx] * v) % MOD; }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) { ans ^= a[i]; }
    return ans;
  }
};
