// 1424. Diagonal Traverse II
// https://leetcode.com/problems/diagonal-traverse-ii/

#include <map>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    int N = nums.size();
    map<int, priority_queue<pair<int, int>>> diags;
    for (int i = 0; i < N; ++i) {
      int M = nums[i].size();
      for (int j = 0; j < M; ++j) {
        int diag = i + j;
        diags[diag].push(make_pair(i, nums[i][j]));
      }
    }
    vector<int> res;
    for (auto itr = diags.begin(); itr != diags.end(); ++itr) {
      priority_queue<pair<int, int>> pq = itr->second;
      while (!pq.empty()) {
        pair<int, int> curr = pq.top();
        pq.pop();
        res.push_back(curr.second);
      }
    }
    return res;
  }
};
