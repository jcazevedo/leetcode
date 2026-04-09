// 3655. XOR After Range Multiplication Queries II
// https://leetcode.com/problems/xor-after-range-multiplication-queries-ii/

#include <cmath>
#include <tuple>
#include <vector>

using namespace std;

#define MOD 1000000007

class Solution {
  long long modpow(long long base, long long exp) {
    long long result = 1;
    base %= MOD;
    while (exp > 0) {
      if (exp & 1) { result = result * base % MOD; }
      base = base * base % MOD;
      exp >>= 1;
    }
    return result;
  }

 public:
  int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size();
    int q = queries.size();
    int T = max(2, (int)sqrt((double)n) + 1);
    vector<long long> mult(n, 1);
    vector<long long> inv_v(100001, 0);
    vector<vector<int>> small_q(T);
    for (int qi = 0; qi < q; qi++) {
      int k = queries[qi][2];
      if (k >= T) {
        int l = queries[qi][0], r = queries[qi][1], v = queries[qi][3];
        for (int idx = l; idx <= r; idx += k) { mult[idx] = mult[idx] * v % MOD; }
      } else {
        small_q[k].push_back(qi);
        int v = queries[qi][3];
        if (!inv_v[v]) { inv_v[v] = modpow(v, MOD - 2); }
      }
    }
    vector<long long> diff(n + 2, 1);
    for (int k = 1; k < T; k++) {
      if (small_q[k].empty()) { continue; }
      vector<vector<tuple<int, int, int>>> by_res(k);
      for (int qi : small_q[k]) {
        int l = queries[qi][0], r = queries[qi][1], v = queries[qi][3];
        int res = l % k;
        int va = l / k;
        int vb = va + (r - l) / k;
        by_res[res].emplace_back(va, vb, v);
      }
      for (int res = 0; res < k && res < n; res++) {
        if (by_res[res].empty()) { continue; }
        int sz = (n - 1 - res) / k + 1;
        vector<int> touched;
        for (const tuple<int, int, int>& t : by_res[res]) {
          int va = get<0>(t), vb = get<1>(t), v = get<2>(t);
          if (diff[va] == 1) { touched.push_back(va); }
          diff[va] = diff[va] * v % MOD;
          if (diff[vb + 1] == 1) { touched.push_back(vb + 1); }
          diff[vb + 1] = diff[vb + 1] * inv_v[v] % MOD;
        }
        long long cur = 1;
        for (int j = 0; j < sz; j++) {
          cur = cur * diff[j] % MOD;
          mult[res + j * k] = mult[res + j * k] * cur % MOD;
        }
        for (int pos : touched) { diff[pos] = 1; }
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) { ans ^= (int)(1LL * nums[i] * mult[i] % MOD); }
    return ans;
  }
};
