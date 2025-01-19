// 3426. Manhattan Distances of All Arrangements of Pieces
// https://leetcode.com/problems/manhattan-distances-of-all-arrangements-of-pieces/

#include <cmath>
#include <vector>

using namespace std;

#define MOD 1000000007

class Solution {
 private:
  long long modAdd(long long a, long long b) { return (a + b) % MOD; }

  long long modMult(long long a, long long b) { return (a * b) % MOD; }

  long long modDiv(long long a, long long b) {
    long long bInv = 1L;
    long long exp = MOD - 2;
    while (exp > 0) {
      if (exp % 2 == 1) { bInv = modMult(bInv, b); }
      b = modMult(b, b);
      exp /= 2;
    }
    return modMult(a, bInv);
  }

  long long modComb(long long n, long long k) {
    if (k > n) { return 0L; }
    long long numer = 1, denom = 1L;
    for (long long i = 0; i < k; ++i) {
      numer = modMult(numer, n - i);
      denom = modMult(denom, i + 1);
    }
    return modDiv(numer, denom);
  }

  long long seriesSum(long long n) { return modDiv(modMult(n, n + 1), 2); }

 public:
  int distanceSum(int m, int n, int k) {
    long long comb = modComb(m * n - 2, k - 2);
    long long ans = 0L;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        long long rowDist = 0L;
        rowDist = modAdd(rowDist, seriesSum(n - j - 1));
        rowDist = modAdd(rowDist, seriesSum(j));
        long long totDists = 0L;
        totDists = modAdd(totDists, modMult(rowDist, m));
        totDists = modAdd(totDists, modMult(seriesSum(m - i - 1), n));
        totDists = modAdd(totDists, modMult(seriesSum(i), n));
        ans = modAdd(ans, modMult(totDists, comb));
      }
    }
    return modDiv(ans, 2);
  }
};
