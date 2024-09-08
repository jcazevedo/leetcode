// 2028. Find Missing Observations
// https://leetcode.com/problems/find-missing-observations/

#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
    int m = rolls.size(), nSum = mean * (n + m);
    for (int roll : rolls) { nSum -= roll; }
    int div = nSum / n, rem = nSum % n;
    if (div <= 0 || div > 6 || (div == 6 && rem != 0)) { return vector<int>(); }
    vector<int> ans(n, div);
    for (int i = 0; i < n && rem > 0; ++i) {
      ans[i] += 1;
      --rem;
    }
    return ans;
  }
};
