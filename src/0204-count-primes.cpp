// 204. Count Primes
// https://leetcode.com/problems/count-primes/

#include <vector>

using namespace std;

class Solution {
 public:
  int countPrimes(int n) {
    vector<bool> isPrime(n, true);
    for (int p = 2; p * p < n; ++p) {
      if (isPrime[p]) {
        for (int i = p * p; i < n; i += p) isPrime[i] = false;
      }
    }
    int ans = 0;
    for (int p = 2; p < n; ++p)
      if (isPrime[p]) ++ans;
    return ans;
  }
};
