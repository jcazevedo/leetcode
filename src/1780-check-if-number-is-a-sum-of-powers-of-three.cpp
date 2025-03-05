// 1780. Check if Number is a Sum of Powers of Three
// https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/

#include <unordered_map>

using namespace std;

#define MAXN 1e7
#define MAXP 15

class Solution {
 private:
  bool good(int n, int p, unordered_map<int, unordered_map<int, bool>>& cache) {
    if (n < 0) { return false; }
    if (n == 0) { return true; }
    if (cache.count(n) && cache[n].count(p)) { return cache[n][p]; }
    cache[n][p] = 0;
    int pow = 1;
    for (int i = 0; i < p; ++i) { pow *= 3; }
    for (int i = p; i < MAXP && n - pow >= 0; ++i) {
      if (good(n - pow, i + 1, cache)) {
        cache[n][p] = 1;
        break;
      }
      pow *= 3;
    }
    return cache[n][p];
  }

 public:
  bool checkPowersOfThree(int n) {
    unordered_map<int, unordered_map<int, bool>> cache;
    return good(n, 0, cache);
  }
};
