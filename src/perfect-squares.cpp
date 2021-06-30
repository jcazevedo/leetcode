#include <vector>

using namespace std;

class Solution {
private:
  vector<int> cache;

public:
  int numSquares(int n) {
    if (cache.size() == 0)
      cache.push_back(0);
    while (cache.size() <= n) {
      int c = cache.size();
      int best = c;
      for (int i = 1; i * i <= c; i++) {
        best = min(best, cache[c - i * i] + 1);
      }
      cache.push_back(best);
    }
    return cache[n];
  }
};
