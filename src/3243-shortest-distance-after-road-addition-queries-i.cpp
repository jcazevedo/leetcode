// 3243. Shortest Distance After Road Addition Queries I
// https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i/

#include <limits>
#include <vector>

using namespace std;

class Solution {
 private:
  void computeDistance(int n, const vector<vector<int>>& from, vector<int>& dist) {
    dist[0] = 0;
    for (int i = 1; i < n; ++i) { dist[i] = numeric_limits<int>::max(); }
    for (int i = 1; i < n; ++i) {
      for (int f : from[i]) { dist[i] = min(dist[i], dist[f] + 1); }
    }
  }

 public:
  vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
    vector<vector<int>> from(n, vector<int>());
    for (int i = 1; i < n; ++i) { from[i].push_back(i - 1); }
    vector<int> dist(n);
    int Q = queries.size();
    vector<int> ans(Q);
    for (int i = 0; i < Q; ++i) {
      from[queries[i][1]].push_back(queries[i][0]);
      computeDistance(n, from, dist);
      ans[i] = dist[n - 1];
    }
    return ans;
  }
};
