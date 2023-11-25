// 2542. Maximum Subsequence Score
// https://leetcode.com/problems/maximum-subsequence-score/

#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
 public:
  long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<tuple<int, int>> values;
    int N = nums1.size();
    for (int i = 0; i < N; ++i) values.push_back({nums2[i], nums1[i]});
    sort(values.begin(), values.end());
    priority_queue<int, vector<int>, greater<int>> bestValues;
    long long currSum = 0L;
    long long ans = 0L;
    for (int i = N - 1; i >= N - k; --i) {
      currSum += get<1>(values[i]);
      bestValues.push(get<1>(values[i]));
    }
    ans = currSum * get<0>(values[N - k]);
    for (int i = N - k - 1; i >= 0; --i) {
      int currMin = get<0>(values[i]);
      int currValue = get<1>(values[i]);
      int smallest = bestValues.top();
      currSum -= smallest;
      currSum += currValue;
      ans = max(ans, currSum * currMin);
      if (smallest < currValue) {
        bestValues.pop();
        bestValues.push(currValue);
      } else {
        currSum -= currValue;
        currSum += smallest;
      }
    }
    return ans;
  }
};
