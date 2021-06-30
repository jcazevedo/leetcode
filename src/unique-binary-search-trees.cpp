#include <vector>

using namespace std;

class Solution {
private:
  vector<int> cache;

  int go(int n) {
    if (cache[n] != -1)
      return cache[n];
    if (n <= 1)
      return cache[n] = 1;
    int tot = 0;
    for (int i = 1; i <= n; ++i)
      tot += go(i - 1) * go(n - i);
    return cache[n] = tot;
  }

public:
  int numTrees(int n) {
    cache.assign(n + 1, -1);
    return go(n);
  }
};
