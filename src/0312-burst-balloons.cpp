// 312. Burst Balloons
// https://leetcode.com/problems/burst-balloons/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
  vector<vector<int>> cache;

  int go(int i, int j, vector<int>& nums) {
    if (cache[i][j] == -1) {
      cache[i][j] = 0;
      if (j - i > 1) {
        for (int k = i + 1; k < j; ++k) {
          cache[i][j] = max(cache[i][j], nums[i] * nums[k] * nums[j] +
                                             go(i, k, nums) + go(k, j, nums));
        }
      }
    }
    return cache[i][j];
  }

public:
  int maxCoins(vector<int>& nums) {
    vector<int> padded = {1};
    for (int num : nums)
      padded.push_back(num);
    padded.push_back(1);
    int N = padded.size();
    cache = vector<vector<int>>(N, vector<int>(N, -1));
    return go(0, N - 1, padded);
  }
};
