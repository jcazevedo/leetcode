// 2554. Maximum Number of Integers to Choose From a Range I
// https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/

#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxCount(vector<int>& banned, int n, int maxSum) {
    unordered_set<int> bannedSet;
    for (int b : banned) { bannedSet.insert(b); }
    int tot = 0, ans = 0;
    for (int i = 1; i <= n; ++i) {
      if (bannedSet.find(i) != bannedSet.end()) { continue; }
      if (tot + i > maxSum) { break; }
      tot += i;
      ++ans;
    }
    return ans;
  }
};
