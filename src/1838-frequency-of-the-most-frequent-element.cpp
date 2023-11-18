// 1838. Frequency of the Most Frequent Element
// https://leetcode.com/problems/frequency-of-the-most-frequent-element/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int maxFrequency(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int N = nums.size();
    long long sum = 0;
    int j = 0, ans = 0;
    for (int i = 0; i < N; ++i) {
      sum += nums[i];
      while (((long long)(i - j + 1)) * nums[i] - sum > k) {
        sum -= nums[j];
        j++;
      }
      ans = max(ans, i - j + 1);
    }
    return ans;
  }
};
