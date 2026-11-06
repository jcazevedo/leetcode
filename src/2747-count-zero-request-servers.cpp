// 2747. Count Zero Request Servers
// https://leetcode.com/problems/count-zero-request-servers/

#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
    sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
    vector<pair<int, int>> sortedQueries;
    for (int i = 0; i < (int)queries.size(); ++i) { sortedQueries.emplace_back(queries[i], i); }
    sort(sortedQueries.begin(), sortedQueries.end());
    vector<int> count(n + 1, 0);
    vector<int> ans(queries.size());
    int left = 0;
    int right = 0;
    int active = 0;
    for (const pair<int, int>& query : sortedQueries) {
      int time = query.first;
      int index = query.second;
      while (right < (int)logs.size() && logs[right][1] <= time) {
        if (count[logs[right][0]]++ == 0) { ++active; }
        ++right;
      }
      while (left < right && logs[left][1] < time - x) {
        if (--count[logs[left][0]] == 0) { --active; }
        ++left;
      }
      ans[index] = n - active;
    }
    return ans;
  }
};
