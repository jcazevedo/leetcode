// 486. Predict the Winner
// https://leetcode.com/problems/predict-the-winner/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 private:
  int bestScore(int p, int l, int r, vector<vector<vector<int>>>& cache, const vector<int>& nums, int maxScore) {
    if (cache[p][l][r] != -1) { return cache[p][l][r]; }
    if (l == r) {
      cache[p][l][r] = nums[l];
    } else {
      int takeLeft = bestScore(p ^ 1, l + 1, r, cache, nums, maxScore - nums[l]);
      int takeRight = bestScore(p ^ 1, l, r - 1, cache, nums, maxScore - nums[r]);
      cache[p][l][r] = max(maxScore - takeLeft, maxScore - takeRight);
    }
    return cache[p][l][r];
  }

 public:
  bool predictTheWinner(vector<int>& nums) {
    int n = nums.size();
    int maxScore = 0;
    for (int num : nums) { maxScore += num; }
    vector<vector<vector<int>>> cache(2, vector<vector<int>>(n, vector<int>(n, -1)));
    int best = bestScore(0, 0, n - 1, cache, nums, maxScore);
    return best >= maxScore - best;
  }
};
