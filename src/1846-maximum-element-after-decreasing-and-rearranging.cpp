// 1846. Maximum Element After Decreasing and Rearranging
// https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    int N = arr.size();

    sort(arr.begin(), arr.end());
    arr[0] = 1;
    for (int i = 1; i < N; ++i)
      arr[i] = min(arr[i], arr[i - 1] + 1);

    return arr[N - 1];
  }
};
