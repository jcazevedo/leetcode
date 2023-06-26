// 1672. Richest Customer Wealth
// https://leetcode.com/problems/richest-customer-wealth/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int maximumWealth(vector<vector<int>>& accounts) {
    int ans = 0;
    for (int i = 0; i < (int)accounts.size(); ++i) {
      int wealth = 0;
      for (int j = 0; j < (int)accounts[i].size(); ++j)
        wealth += accounts[i][j];
      ans = max(ans, wealth);
    }
    return ans;
  }
};
