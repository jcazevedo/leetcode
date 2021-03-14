#include <vector>

using namespace std;

class Solution {
public:
  vector<int> majorityElement(vector<int>& nums) {
    vector<int> ans;
    int N = nums.size();
    if (N == 0)
      return ans;
    int v1 = nums[0], v2 = nums[0], cnt1 = 1, cnt2 = 0;
    for (int i = 1; i < N; ++i) {
      if (nums[i] == v1) {
        cnt1++;
      } else if (nums[i] == v2) {
        cnt2++;
      } else if (cnt1 == 0) {
        v1 = nums[i];
        cnt1++;
      } else if (cnt2 == 0) {
        v2 = nums[i];
        cnt2++;
      } else {
        cnt1--;
        cnt2--;
      }
    }
    cnt1 = cnt2 = 0;
    for (int i = 0; i < N; ++i) {
      if (nums[i] == v1)
        cnt1++;
      else if (nums[i] == v2)
        cnt2++;
    }
    if (cnt1 > N / 3)
      ans.push_back(v1);
    if (cnt2 > N / 3)
      ans.push_back(v2);
    return ans;
  }
};
