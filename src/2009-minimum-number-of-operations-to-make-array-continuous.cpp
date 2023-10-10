// 2009. Minimum Number of Operations to Make Array Continuous
// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/

#include <algorithm>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  int minOperations(vector<int>& nums) {
    int N = nums.size();
    set<int> uniques(nums.begin(), nums.end());
    vector<int> arr;
    for (int n : uniques)
      arr.push_back(n);
    int ans = N;
    for (int i = 0; i < (int)arr.size(); ++i) {
      int right = arr[i] + N - 1;
      int j = upper_bound(arr.begin(), arr.end(), right) - arr.begin();
      ans = min(ans, N - (j - i));
    }
    return ans;
  }
};
