#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int findLength(vector<int>& nums1, vector<int>& nums2) {
    int N1 = nums1.size();
    int N2 = nums2.size();
    vector<vector<int>> dp(N1 + 1, vector<int>(N2 + 1, 0));
    int ans = 0;
    for (int i = 0; i < N1; ++i) {
      for (int j = 0; j < N2; ++j) {
        if (nums1[i] == nums2[j])
          dp[i + 1][j + 1] = dp[i][j] + 1;
        ans = max(ans, dp[i + 1][j + 1]);
      }
    }
    return ans;
  }
};
