// 1743. Restore the Array From Adjacent Pairs
// https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/

#include <map>
#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
    map<int, vector<int>> adjacent;
    for (const vector<int>& pair : adjacentPairs) {
      adjacent[pair[0]].push_back(pair[1]);
      adjacent[pair[1]].push_back(pair[0]);
    }

    int start = -1;
    for (auto itr = adjacent.begin(); itr != adjacent.end(); ++itr)
      if (itr->second.size() == 1) {
        start = itr->first;
        break;
      }

    set<int> visited;
    vector<int> ans;
    int curr = start;
    visited.insert(curr);
    ans.push_back(curr);
    while (ans.size() != adjacentPairs.size() + 1) {
      for (int next : adjacent[curr]) {
        if (visited.find(next) == visited.end()) {
          visited.insert(next);
          ans.push_back(next);
          curr = next;
          break;
        }
      }
    }

    return ans;
  }
};
