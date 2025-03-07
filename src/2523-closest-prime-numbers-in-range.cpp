// 2523. Closest Prime Numbers in Range
// https://leetcode.com/problems/closest-prime-numbers-in-range/

#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> closestPrimes(int left, int right) {
    vector<bool> isPrime(right + 1, true);
    isPrime[1] = false;
    for (int p = 2; p * p <= right; ++p) {
      if (isPrime[p]) {
        for (int i = p * p; i <= right; i += p) { isPrime[i] = false; }
      }
    }
    vector<int> primes;
    for (int p = left; p <= right; ++p) {
      if (isPrime[p]) { primes.push_back(p); }
    }
    vector<int> ans = {-1, -1};
    int n = primes.size();
    for (int i = 0; i < n - 1; ++i) {
      if (ans[0] == -1 || primes[i + 1] - primes[i] < ans[1] - ans[0]) { ans = {primes[i], primes[i + 1]}; }
    }
    return ans;
  }
};
