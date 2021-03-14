#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    int N = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int> > res;
    for (int i = 0; i < N; i++) {
      if (i == 0 || nums[i] != nums[i - 1]) {
        int l = i + 1;
        int r = N - 1;
        while (l < r) {
          int s = nums[i] + nums[l] + nums[r];
          if (s == 0) {
            vector<int> rr;
            rr.push_back(nums[i]);
            rr.push_back(nums[l]);
            rr.push_back(nums[r]);
            res.push_back(rr);
            while (l < r && nums[l] == nums[l + 1])
              l++;
            while (l < r && nums[r] == nums[r - 1])
              r--;
            l++;
            r--;
          } else if (s > 0) {
            r--;
          } else {
            l++;
          }
        }
      }
    }
    return res;
  }
};

