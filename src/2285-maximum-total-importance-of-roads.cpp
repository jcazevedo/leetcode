// 2285. Maximum Total Importance of Roads
// https://leetcode.com/problems/maximum-total-importance-of-roads/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  long long maximumImportance(int n, vector<vector<int>>& roads) {
    vector<int> degree(n, 0);
    for (const vector<int>& road : roads) {
      ++degree[road[0]];
      ++degree[road[1]];
    }
    vector<vector<int>> degreeWithCity;
    for (int i = 0; i < n; ++i) { degreeWithCity.push_back({degree[i], i}); }
    sort(degreeWithCity.begin(), degreeWithCity.end());
    long long ans = 0L;
    long long importance = n;
    for (int i = n - 1; i >= 0; --i) {
      ans += degreeWithCity[i][0] * importance;
      --importance;
    }
    return ans;
  }
};
