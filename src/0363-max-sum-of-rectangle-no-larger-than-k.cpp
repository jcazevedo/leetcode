// 363. Max Sum of Rectangle No Larger Than K
// https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/

#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  int maxSumSubmatrix(vector<vector<int>>& matrix, int max_sum) {
    int H = matrix.size();
    int W = matrix[0].size();
    vector<vector<int>> prefix = vector<vector<int>>(H, vector<int>(W, 0));
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        prefix[i][j] = matrix[i][j];
        if (j > 0)
          prefix[i][j] += prefix[i][j - 1];
      }
    }
    bool is_set = false;
    int ans = -1;
    for (int i = 0; i < W; ++i) {
      for (int j = i; j < W; ++j) {
        vector<int> v;
        for (int k = 0; k < H; ++k) {
          int row_sum = 0;
          row_sum = prefix[k][j];
          if (i > 0)
            row_sum -= prefix[k][i - 1];
          v.push_back(row_sum);
        }
        set<int> cum_set;
        cum_set.insert(0);
        int curr_sum = 0;
        for (int k = 0; k < (int)v.size(); ++k) {
          curr_sum += v[k];
          set<int>::iterator sit = cum_set.lower_bound(curr_sum - max_sum);
          if (sit != cum_set.end() && (!is_set || curr_sum - *sit > ans)) {
            is_set = true;
            ans = curr_sum - *sit;
          }
          cum_set.insert(curr_sum);
        }
      }
    }
    return ans;
  }
};
