// 1052. Grumpy Bookstore Owner
// https://leetcode.com/problems/grumpy-bookstore-owner/

#include <vector>

using namespace std;

class Solution {
 public:
  int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
    int n = customers.size();
    vector<int> prefix(n, 0);
    int ans = grumpy[0] ? 0 : customers[0];
    prefix[0] = grumpy[0] ? customers[0] : 0;
    for (int i = 1; i < n; ++i) {
      ans += (grumpy[i] ? 0 : customers[i]);
      prefix[i] = prefix[i - 1] + (grumpy[i] ? customers[i] : 0);
    }
    int best = 0;
    int bestSum = prefix[minutes - 1];
    for (int i = 1; i + minutes <= n; ++i) {
      int sum = prefix[i + minutes - 1] - prefix[i - 1];
      if (sum > bestSum) {
        best = i;
        bestSum = sum;
      }
    }
    return ans + prefix[best + minutes - 1] - (best > 0 ? prefix[best - 1] : 0);
  }
};
