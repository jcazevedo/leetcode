// 1992. Find All Groups of Farmland
// https://leetcode.com/problems/find-all-groups-of-farmland/

#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> findFarmland(vector<vector<int>>& land) {
    int m = land.size();
    int n = land[0].size();

    map<vector<int>, vector<int>> farmlandStart;
    map<vector<int>, vector<int>> farmlands;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (land[i][j]) {
          if (i > 0 && land[i - 1][j]) {
            farmlandStart[{i, j}] = farmlandStart[{i - 1, j}];
          } else if (j > 0 && land[i][j - 1]) {
            farmlandStart[{i, j}] = farmlandStart[{i, j - 1}];
          } else {
            farmlandStart[{i, j}] = {i, j};
          }
          farmlands[farmlandStart[{i, j}]] = {i, j};
        }
      }
    }

    vector<vector<int>> ans;
    for (auto itr = farmlands.begin(); itr != farmlands.end(); ++itr) {
      ans.push_back({itr->first[0], itr->first[1], itr->second[0], itr->second[1]});
    }

    return ans;
  }
};
