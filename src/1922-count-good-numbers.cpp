// 1922. Count Good Numbers
// https://leetcode.com/problems/count-good-numbers/

#define MOD 1000000007

class Solution {
 public:
  long long power(long long base, long long exp) {
    long long result = 1;
    base %= MOD;
    while (exp > 0) {
      if (exp % 2 == 1) result = (result * base) % MOD;
      base = (base * base) % MOD;
      exp /= 2;
    }
    return result;
  }

  int countGoodNumbers(long long n) {
    long long even = (n + 1) / 2;
    long long odd = n / 2;
    return power(5, even) * power(4, odd) % MOD;
  }
};
