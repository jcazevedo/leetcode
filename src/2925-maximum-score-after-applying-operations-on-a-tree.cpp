// 2925. Maximum Score After Applying Operations on a Tree
// https://leetcode.com/problems/maximum-score-after-applying-operations-on-a-tree/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 private:
  long long getMinimumToKeep(int u,
                             const vector<vector<int>>& connections,
                             const vector<int>& values,
                             vector<bool>& inPath) {
    long long removeRoot = values[u];

    long long removeFromChildren = 0L;
    for (int v : connections[u]) {
      if (inPath[v]) continue;
      inPath[v] = true;
      removeFromChildren += getMinimumToKeep(v, connections, values, inPath);
      inPath[v] = false;
    }

    if (removeFromChildren == 0L) return removeRoot;

    return min(removeRoot, removeFromChildren);
  }

 public:
  long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
    int N = values.size();

    long long totalScore = 0L;
    for (int v : values) totalScore += v;

    vector<vector<int>> connections(N, vector<int>());
    for (const vector<int>& edge : edges) {
      connections[edge[0]].push_back(edge[1]);
      connections[edge[1]].push_back(edge[0]);
    }

    vector<bool> inPath(N, false);
    inPath[0] = true;
    long long minimumRemaining = getMinimumToKeep(0, connections, values, inPath);

    return totalScore - minimumRemaining;
  }
};
