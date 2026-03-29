// 2338. Count the Number of Ideal Arrays
// https://leetcode.com/problems/count-the-number-of-ideal-arrays/

#include <vector>

using namespace std;

#define MOD 1000000007
#define MAX_K 15

class Solution {
 public:
  int idealArrays(int n, int maxValue) {
    vector<vector<int>> dp(maxValue + 1, vector<int>(MAX_K, 0));
    for (int v = 1; v <= maxValue; v++) { dp[v][0] = 1; }
    for (int k = 0; k + 1 < MAX_K; k++) {
      for (int v = 1; v <= maxValue; v++) {
        if (dp[v][k] == 0) { continue; }
        for (int m = 2 * v; m <= maxValue; m += v) { dp[m][k + 1] = (dp[m][k + 1] + dp[v][k]) % MOD; }
      }
    }
    vector<long long> comb(MAX_K, 0);
    comb[0] = 1;
    for (int i = 1; i < min(n, MAX_K); i++) {
      comb[i] = comb[i - 1] % MOD * ((n - i) % MOD) % MOD;
      long long inv = 1, base = i, exp = MOD - 2;
      while (exp > 0) {
        if (exp & 1) { inv = inv * base % MOD; }
        base = base * base % MOD;
        exp /= 2;
      }
      comb[i] = comb[i] * inv % MOD;
    }
    long long ans = 0;
    for (int v = 1; v <= maxValue; v++) {
      for (int k = 0; k < MAX_K; k++) {
        if (dp[v][k] == 0) { continue; }
        ans = (ans + (long long)dp[v][k] % MOD * comb[k]) % MOD;
      }
    }
    return ans;
  }
};
