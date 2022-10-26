// 954. Array of Doubled Pairs
// https://leetcode.com/problems/array-of-doubled-pairs/

#include <algorithm>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canReorderDoubled(vector<int>& arr) {
    int N = arr.size();
    sort(arr.begin(), arr.end());
    unordered_map<int, set<int>> idxs;
    for (int i = 0; i < N; ++i) idxs[arr[i]].insert(i);
    vector<bool> used(N, false);
    for (int i = 0; i < N; ++i) {
      if (used[i]) continue;
      int value = arr[i];
      if (value < 0 && abs(value) % 2 != 0) return false;
      int target = value < 0 ? value / 2 : value * 2;
      if (idxs[target].empty()) return false;
      int found = *idxs[target].begin();
      idxs[target].erase(found);
      used[found] = true;
      used[i] = true;
    }
    return true;
  }
};
