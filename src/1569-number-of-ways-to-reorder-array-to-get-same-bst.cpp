// 1569. Number of Ways to Reorder Array to Get Same BST
// https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/

#include <vector>

using namespace std;

#define MAXN 1000
#define MOD 1000000007

class Solution {
 private:
  long long pt[MAXN + 1][MAXN + 1];

  long long go(vector<int>& nums) {
    if (nums.size() <= 1) return 1L;
    vector<int> left, right;
    for (int i = 1; i < (int)nums.size(); ++i)
      if (nums[i] < nums[0])
        left.push_back(nums[i]);
      else
        right.push_back(nums[i]);
    return (((pt[nums.size() - 1][left.size()] * go(left)) % MOD) * go(right)) % MOD;
  }

 public:
  int numOfWays(vector<int>& nums) {
    for (int i = 0; i <= MAXN; ++i)
      for (int j = 0; j <= i; ++j)
        if (j == 0 || j == i)
          pt[i][j] = 1L;
        else
          pt[i][j] = (pt[i - 1][j - 1] + pt[i - 1][j]) % MOD;
    return (go(nums) - 1) % MOD;
  }
};
