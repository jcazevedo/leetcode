// 1420. Build Array Where You Can Find The Maximum Exactly K Comparisons
// https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/

#include <vector>

using namespace std;

#define MOD 1000000007L

class Solution {
private:
  int ways(int n, int m, int k, vector<vector<vector<int>>>& cache) {
    if (k == 0) {
      if (n == 0)
        return 1;
      return 0;
    }
    if (m == 0)
      return 0;
    if (cache[n][m][k] == -1) {
      long long ans = 0;
      for (int i = 0; i < n; ++i) {
        long long right = 1;
        for (int r = i + 1; r < n; ++r)
          right = (right * m) % MOD;
        long long left = 0;
        if (i == 0 && k == 1)
          ans = (ans + right) % MOD;
        else
          for (int m1 = 1; m1 < m; ++m1)
            left = (left + ways(i, m1, k - 1, cache)) % MOD;
        ans = (ans + (left * right % MOD)) % MOD;
      }
      cache[n][m][k] = ans % MOD;
    }
    return cache[n][m][k];
  }

public:
  int numOfArrays(int n, int m, int k) {
    vector<vector<vector<int>>> cache(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, -1)));
    long long ans = 0;
    for (int i = 1; i <= m; ++i)
      ans = (ans + ways(n, i, k, cache)) % MOD;
    return ans;
  }
};
