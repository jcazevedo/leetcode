// 2300. Successful Pairs of Spells and Potions
// https://leetcode.com/problems/successful-pairs-of-spells-and-potions/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    int n = spells.size();
    sort(potions.begin(), potions.end());
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
      long long threshold = (success + spells[i] - 1) / spells[i];
      vector<int>::iterator it = lower_bound(potions.begin(), potions.end(), threshold);
      ans[i] = potions.end() - it;
    }
    return ans;
  }
};
