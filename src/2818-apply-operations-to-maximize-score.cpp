// 2818. Apply Operations to Maximize Score
// https://leetcode.com/problems/apply-operations-to-maximize-score/

#include <algorithm>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define MOD 1000000007

class Solution {
 private:
  int nPrimeFactors(int n) {
    int ans = 0;
    if (n % 2 == 0) {
      ++ans;
      while (n % 2 == 0) { n /= 2; }
    }
    for (int i = 3; i * i <= n; i += 2) {
      if (n % i == 0) {
        ++ans;
        while (n % i == 0) { n /= i; }
      }
    }
    if (n > 2) { ++ans; }
    return ans;
  }

  long long modMult(long long a, long long b) { return (a * b) % MOD; }

  long long modPow(long long n, long long p) {
    long long ans = 1L;
    while (p > 0) {
      if (p & 1) { ans = modMult(ans, n); }
      n = modMult(n, n);
      p >>= 1;
    }
    return ans;
  }

 public:
  int maximumScore(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> scores(n);
    for (int i = 0; i < n; ++i) { scores[i] = nPrimeFactors(nums[i]); }
    vector<int> next(n, n), prev(n, -1);
    stack<int> s;
    for (int i = 0; i < n; ++i) {
      while (!s.empty() && scores[s.top()] < scores[i]) {
        int top = s.top();
        s.pop();
        next[top] = i;
      }
      if (!s.empty()) { prev[i] = s.top(); }
      s.push(i);
    }
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; ++i) { pq.push({nums[i], i}); }
    long long ans = 1L;
    while (k > 0) {
      pair<int, int> curr = pq.top();
      pq.pop();
      long long ops =
          min(((long long)(next[curr.second] - curr.second)) * (curr.second - prev[curr.second]), (long long)k);
      ans = modMult(ans, modPow(curr.first, ops));
      k -= ops;
    }
    return ans;
  }
};
