// 3337. Total Characters in String After Transformations II
// https://leetcode.com/problems/total-characters-in-string-after-transformations-ii/

#include <string>
#include <vector>

using namespace std;

#define MOD 1000000007

class Solution {
 private:
  long long modAdd(long long a, long long b) { return (a + b) % MOD; }

  long long modMult(long long a, long long b) { return (a * b) % MOD; }

  vector<vector<long long>> matrixMult(const vector<vector<long long>>& a, const vector<vector<long long>>& b) {
    vector<vector<long long>> ans(26, vector<long long>(26, 0));
    for (int i = 0; i < 26; ++i) {
      for (int j = 0; j < 26; ++j) {
        for (int k = 0; k < 26; ++k) { ans[i][j] = modAdd(ans[i][j], modMult(a[i][k], b[k][j])); }
      }
    }
    return ans;
  }

  vector<vector<long long>> matrixPow(vector<vector<long long>> m, int exp) {
    vector<vector<long long>> ans(26, vector<long long>(26, 0));
    for (int i = 0; i < 26; ++i) { ans[i][i] = 1; }
    while (exp > 0) {
      if (exp % 2) { ans = matrixMult(ans, m); }
      m = matrixMult(m, m);
      exp /= 2;
    }
    return ans;
  }

 public:
  int lengthAfterTransformations(string s, int t, vector<int>& nums) {
    vector<long long> cnt(26, 0);
    for (char ch : s) { ++cnt[ch - 'a']; }
    vector<vector<long long>> transform(26, vector<long long>(26, 0));
    for (int i = 0; i < 26; ++i) {
      for (int j = 1; j <= nums[i]; ++j) { ++transform[(i + j) % 26][i]; }
    }
    vector<vector<long long>> pow = matrixPow(transform, t);
    long long ans = 0L;
    for (int i = 0; i < 26; ++i) {
      for (int j = 0; j < 26; ++j) { ans = modAdd(modMult(pow[i][j], cnt[j]), ans); }
    }
    return ans;
  }
};
