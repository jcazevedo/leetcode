#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  int findMaxLength(vector<int>& nums) {
    map<int, int> min_diff;
    min_diff[0] = 0;
    int cnt_0 = 0, cnt_1 = 0, best = 0, N = nums.size();
    for (int i = 0; i < N; ++i) {
      if (nums[i] == 0) cnt_0++;
      else cnt_1++;
      int diff = cnt_0 - cnt_1;
      if (min_diff.find(diff) == min_diff.end())
        min_diff[diff] = i + 1;
      best = max(best, i + 1 - min_diff[diff]);
    }
    return best;
  }
};
