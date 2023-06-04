// 547. Number of Provinces
// https://leetcode.com/problems/number-of-provinces/

#include <vector>

using namespace std;

class Solution {
private:
  void visit(int curr, const vector<vector<int>>& isConnected, vector<bool>& visited) {
    for (int i = 0; i < (int)isConnected[curr].size(); ++i)
      if (isConnected[curr][i] && !visited[i]) {
        visited[i] = true;
        visit(i, isConnected, visited);
      }
  }

public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    int N = isConnected.size();
    vector<bool> visited = vector<bool>(N, false);
    int ans = 0;
    for (int i = 0; i < N; ++i)
      if (!visited[i]) {
        visited[i] = true;
        visit(i, isConnected, visited);
        ++ans;
      }
    return ans;
  }
};
