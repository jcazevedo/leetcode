// 3005. Count Elements With Maximum Frequency
// https://leetcode.com/problems/count-elements-with-maximum-frequency/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxFrequencyElements(vector<int>& nums) {
    int ans = 0, maxFreq = 0;
    unordered_map<int, int> cnt;
    for (int num : nums) {
      cnt[num] += 1;
      if (cnt[num] == maxFreq) {
        ans += maxFreq;
      } else if (cnt[num] > maxFreq) {
        ans = cnt[num];
        maxFreq = cnt[num];
      }
    }
    return ans;
  }
};
