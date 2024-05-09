// 3075. Maximize Happiness of Selected Children
// https://leetcode.com/problems/maximize-happiness-of-selected-children/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  long long maximumHappinessSum(vector<int>& happiness, int k) {
    sort(happiness.begin(), happiness.end());
    reverse(happiness.begin(), happiness.end());
    long long ans = 0L;
    for (int i = 0; i < k; ++i) ans += max(happiness[i] - i, 0);
    return ans;
  }
};
