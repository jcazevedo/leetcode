// 1399. Count Largest Group
// https://leetcode.com/problems/count-largest-group/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int countLargestGroup(int n) {
    int maxSum = 9 * 4 + 1;
    vector<int> freq(maxSum, 0);
    for (int i = 1; i <= n; ++i) {
      int sum = 0, num = i;
      while (num) {
        sum += num % 10;
        num /= 10;
      }
      ++freq[sum];
    }
    int best = *max_element(freq.begin(), freq.end());
    int ans = 0;
    for (int f : freq) {
      if (f == best) { ++ans; }
    }
    return ans;
  }
};
