// 864. Shortest Path to Get All Keys
// https://leetcode.com/problems/shortest-path-to-get-all-keys/

#include <cstdio>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int shortestPathAllKeys(vector<string>& grid) {
    unordered_map<char, int> keyToIdx;
    unordered_map<int, char> idxToKey;
    int startI, startJ, nKeys = 0, H = grid.size(), W = grid[0].size();

    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        if (grid[i][j] == '@') {
          startI = i;
          startJ = j;
        }

        if (islower(grid[i][j])) {
          keyToIdx[grid[i][j]] = nKeys;
          idxToKey[nKeys] = grid[i][j];
          ++nKeys;
        }
      }
    }

    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    tuple<int, int, int, int> start = {startI, startJ, 0, 0};
    queue<tuple<int, int, int, int>> q;
    set<tuple<int, int, int>> visited;
    q.push(start);
    visited.insert({startI, startJ, 0});
    while (!q.empty()) {
      int currI, currJ, currKeys, currDist;
      tie(currI, currJ, currKeys, currDist) = q.front();
      q.pop();

      for (int d = 0; d < (int)directions.size(); ++d) {
        int nextI = currI + directions[d][0];
        int nextJ = currJ + directions[d][1];

        if (nextI >= 0 && nextI < H && nextJ >= 0 && nextJ < W) {
          if ((grid[nextI][nextJ] == '.' || grid[nextI][nextJ] == '@') &&
              visited.find({nextI, nextJ, currKeys}) == visited.end()) {
            q.push({nextI, nextJ, currKeys, currDist + 1});
            visited.insert({nextI, nextJ, currKeys});
          }

          if (islower(grid[nextI][nextJ])) {
            int nextKey = keyToIdx[grid[nextI][nextJ]];
            int nextKeys = (1 << nextKey) | currKeys;
            if (nextKeys == (1 << nKeys) - 1) return currDist + 1;
            if (visited.find({nextI, nextJ, nextKeys}) == visited.end()) {
              q.push({nextI, nextJ, nextKeys, currDist + 1});
              visited.insert({nextI, nextJ, nextKeys});
            }
          }

          if (isupper(grid[nextI][nextJ])) {
            int keyNeeded = keyToIdx[tolower(grid[nextI][nextJ])];
            if (((1 << keyNeeded) & currKeys) &&
                visited.find({nextI, nextJ, currKeys}) == visited.end()) {
              q.push({nextI, nextJ, currKeys, currDist + 1});
              visited.insert({nextI, nextJ, currKeys});
            }
          }
        }
      }
    }
    return -1;
  }
};
