// 3354. Make Array Elements Equal to Zero
// https://leetcode.com/problems/make-array-elements-equal-to-zero/

#include <vector>

using namespace std;

class Solution {
 public:
  int countValidSelections(vector<int>& nums) {
    int N = nums.size();
    int ans = 0;
    for (int i = 0; i < N; ++i) {
      if (nums[i] != 0) { continue; }
      for (int di = -1; di <= 1; di += 2) {
        vector<int> currVec = nums;
        int curr = i;
        int dir = di;
        while (curr >= 0 && curr < N) {
          if (currVec[curr] != 0) {
            --currVec[curr];
            if (dir == -1) {
              dir = 1;
            } else {
              dir = -1;
            }
          }
          curr += dir;
        }
        bool good = true;
        for (int j = 0; j < N && good; ++j) {
          if (currVec[j] != 0) { good = false; }
        }
        if (good) { ++ans; }
      }
    }
    return ans;
  }
};
