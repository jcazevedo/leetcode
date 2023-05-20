// 1010. Pairs of Songs With Total Durations Divisible by 60
// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

#include <vector>

using namespace std;

class Solution {
public:
  int numPairsDivisibleBy60(vector<int>& time) {
    vector<int> cnt = vector<int>(60, 0);
    int ans = 0;
    for (int t : time) {
      int mod = t % 60;
      ans += cnt[(60 - mod) % 60];
      ++cnt[mod];
    }
    return ans;
  }
};
