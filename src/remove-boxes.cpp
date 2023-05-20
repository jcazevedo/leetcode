#include <cstring>
#include <vector>

using namespace std;

#define MAXN 100

class Solution {
private:
  int dp[MAXN][MAXN][MAXN];

  int go(int l, int r, int k, vector<int>& boxes) {
    if (l > r)
      return 0;
    if (dp[l][r][k] != -1)
      return dp[l][r][k];
    int ans = go(l + 1, r, 0, boxes) + (k + 1) * (k + 1);
    for (int j = l + 1; j <= r; ++j) {
      if (boxes[l] == boxes[j])
        ans = max(ans, go(j, r, k + 1, boxes) + go(l + 1, j - 1, 0, boxes));
    }
    dp[l][r][k] = ans;
    return dp[l][r][k];
  }

public:
  int removeBoxes(vector<int>& boxes) {
    int N = boxes.size();
    memset(dp, -1, sizeof(dp));
    return go(0, N - 1, 0, boxes);
  }
};
