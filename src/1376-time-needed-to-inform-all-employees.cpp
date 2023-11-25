// 1376. Time Needed to Inform All Employees
// https://leetcode.com/problems/time-needed-to-inform-all-employees/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
  int getMinTime(int curr, const vector<vector<int>>& subordinates,
                 const vector<int>& informTime) {
    if (subordinates[curr].empty())
      return 0;
    int ans = 0;
    for (int i = 0; i < (int)subordinates[curr].size(); ++i)
      ans =
          max(ans, getMinTime(subordinates[curr][i], subordinates, informTime));
    return ans + informTime[curr];
  }

public:
  int numOfMinutes(int n, int headID, vector<int>& manager,
                   vector<int>& informTime) {
    vector<vector<int>> subordinates = vector<vector<int>>(n, vector<int>());
    for (int i = 0; i < n; ++i)
      if (manager[i] >= 0)
        subordinates[manager[i]].push_back(i);
    return getMinTime(headID, subordinates, informTime);
  }
};
