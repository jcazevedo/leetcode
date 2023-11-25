// 1561. Maximum Number of Coins You Can Get
// https://leetcode.com/problems/maximum-number-of-coins-you-can-get/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxCoins(vector<int>& piles) {
    sort(piles.begin(), piles.end());
    int N = piles.size(), bob = 0, you = N - 2, ans = 0;
    while (bob < you) {
      ans += piles[you];
      you -= 2;
      bob += 1;
    }
    return ans;
  }
};
