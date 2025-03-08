// 2379. Minimum Recolors to Get K Consecutive Black Blocks
// https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int minimumRecolors(string blocks, int k) {
    int n = blocks.size();
    vector<int> p(n, 0);
    p[0] = blocks[0] == 'W' ? 0 : 1;
    for (int i = 1; i < n; ++i) { p[i] = p[i - 1] + (blocks[i] == 'W' ? 0 : 1); }
    int ans = n;
    for (int i = 0; i + k <= n; ++i) {
      int s = p[i + k - 1];
      if (i > 0) { s -= p[i - 1]; }
      ans = min(ans, k - s);
    }
    return ans;
  }
};
