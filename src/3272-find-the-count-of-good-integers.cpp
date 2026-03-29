// 3272. Find the Count of Good Integers
// https://leetcode.com/problems/find-the-count-of-good-integers/

#include <algorithm>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  long long countGoodIntegers(int n, int k) {
    vector<long long> fact(n + 1, 1);
    for (int i = 1; i <= n; ++i) { fact[i] = fact[i - 1] * i; }
    int half = (n + 1) / 2;
    long long lo = 1;
    for (int i = 1; i < half; ++i) { lo *= 10; }
    long long hi = lo * 10;
    set<string> seen;
    long long ans = 0;
    for (long long h = lo; h < hi; ++h) {
      string full = to_string(h);
      for (int i = n / 2 - 1; i >= 0; --i) { full += full[i]; }
      long long val = stoll(full);
      if (val % k != 0) { continue; }
      string sorted_digits = full;
      sort(sorted_digits.begin(), sorted_digits.end());
      if (seen.count(sorted_digits)) { continue; }
      seen.insert(sorted_digits);
      int freq[10] = {};
      for (char c : sorted_digits) { freq[c - '0']++; }
      long long perms = fact[n];
      for (int i = 0; i < 10; ++i) { perms /= fact[freq[i]]; }
      long long with_leading_zero = 0;
      if (freq[0] > 0) {
        freq[0]--;
        with_leading_zero = fact[n - 1];
        for (int i = 0; i < 10; ++i) { with_leading_zero /= fact[freq[i]]; }
        freq[0]++;
      }
      ans += perms - with_leading_zero;
    }
    return ans;
  }
};
