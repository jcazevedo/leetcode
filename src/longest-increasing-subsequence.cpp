#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    int N = nums.size();
    vector<int> p(N);
    vector<int> m(N + 1);
    int ans = 0;
    for (int i = 0; i < N; ++i) {
      int lo = 1, hi = ans;
      while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (nums[m[mid]] < nums[i])
          lo = mid + 1;
        else
          hi = mid - 1;
      }
      int newAns = lo;
      p[i] = m[newAns - 1];
      m[newAns] = i;
      ans = max(ans, newAns);
    }
    return ans;
  }
};
