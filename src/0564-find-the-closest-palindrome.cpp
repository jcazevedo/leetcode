// 564. Find the Closest Palindrome
// https://leetcode.com/problems/find-the-closest-palindrome/

#include <limits>
#include <string>

using namespace std;

class Solution {
 private:
  long long toPalindrome(const long long& num) {
    string s = to_string(num);
    int N = s.length(), l = (N - 1) / 2, r = N / 2;
    while (l >= 0) { s[r++] = s[l--]; }
    return stoll(s);
  }

  long long prevP(long long num) {
    long long l = 0, r = num, ans = numeric_limits<long long>::min();
    while (l <= r) {
      long long m = l + (r - l) / 2;
      long long p = toPalindrome(m);
      if (p < num) {
        ans = p;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    return ans;
  }

  long long nextP(long long num) {
    long long l = num, r = 1e18, ans = numeric_limits<long long>::min();
    while (l <= r) {
      long long m = l + (r - l) / 2;
      long long p = toPalindrome(m);
      if (p > num) {
        ans = p;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    return ans;
  }

 public:
  string nearestPalindromic(string n) {
    long long num = stoll(n), prev = prevP(num), next = nextP(num);
    if (abs(prev - num) <= abs(next - num)) { return to_string(prev); }
    return to_string(next);
  }
};
