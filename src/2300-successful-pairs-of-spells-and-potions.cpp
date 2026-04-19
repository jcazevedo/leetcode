// 2300. Successful Pairs of Spells and Potions
// https://leetcode.com/problems/successful-pairs-of-spells-and-potions/

#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    int n = spells.size(), m = potions.size();
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int a, int b) { return spells[a] < spells[b]; });
    sort(potions.begin(), potions.end(), greater<int>());
    vector<int> ans(n);
    int j = 0;
    for (int i : order) {
      while (j < m && (long long)spells[i] * potions[j] >= success) { ++j; }
      ans[i] = j;
    }
    return ans;
  }
};
