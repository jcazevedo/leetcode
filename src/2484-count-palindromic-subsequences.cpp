// 2484. Count Palindromic Subsequences
// https://leetcode.com/problems/count-palindromic-subsequences/

#include <string>
#include <vector>

using namespace std;

#define MOD 1000000007

class Solution {
 public:
  int countPalindromes(string s) {
    int N = s.size();
    if (N < 5) { return 0; }
    vector<vector<long long>> suf(N + 1, vector<long long>(100, 0L));
    vector<long long> cntR(10, 0);
    for (int i = N - 1; i >= 0; --i) {
      for (int j = 0; j < 100; ++j) { suf[i][j] = suf[i + 1][j]; }
      int d = s[i] - '0';
      for (int y = 0; y < 10; ++y) { suf[i][d * 10 + y] = (suf[i][d * 10 + y] + cntR[y]) % MOD; }
      cntR[d]++;
    }
    vector<long long> pre(100, 0L);
    vector<long long> cntL(10, 0);
    long long ans = 0;
    for (int m = 0; m < N; ++m) {
      for (int x = 0; x < 10; ++x) {
        for (int y = 0; y < 10; ++y) { ans = (ans + pre[x * 10 + y] * suf[m + 1][y * 10 + x]) % MOD; }
      }
      int d = s[m] - '0';
      for (int x = 0; x < 10; ++x) { pre[x * 10 + d] = (pre[x * 10 + d] + cntL[x]) % MOD; }
      cntL[d]++;
    }
    return ans;
  }
};
