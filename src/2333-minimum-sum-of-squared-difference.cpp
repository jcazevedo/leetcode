// 2333. Minimum Sum of Squared Difference
// https://leetcode.com/problems/minimum-sum-of-squared-difference/

#include <cmath>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
    int n = nums1.size();
    unordered_map<long long, long long> frequency;
    priority_queue<long long> differences;
    long long totalDifference = 0L;
    for (int i = 0; i < n; ++i) {
      long long diff = abs(nums1[i] - nums2[i]);
      if (frequency.find(diff) == frequency.end()) { differences.push(diff); }
      ++frequency[diff];
      totalDifference += diff;
    }
    long long k = k1 + k2;
    if (totalDifference <= k) { return 0L; }
    while (k > 0L && !differences.empty()) {
      long long d = differences.top();
      differences.pop();
      if (d == 0L) { break; }
      long long next = differences.empty() ? 0L : differences.top();
      long long count = frequency[d];
      long long needed = (d - next) * count;
      if (k >= needed) {
        k -= needed;
        frequency[next] += count;
        frequency.erase(d);
      } else {
        long long decrease = k / count;
        long long remainder = k % count;
        frequency.erase(d);
        frequency[d - decrease - 1] += remainder;
        frequency[d - decrease] += count - remainder;
        k = 0L;
      }
    }
    long long ans = 0L;
    for (unordered_map<long long, long long>::iterator itr = frequency.begin(); itr != frequency.end(); ++itr) {
      ans += (itr->first * itr->first * itr->second);
    }
    return ans;
  }
};
