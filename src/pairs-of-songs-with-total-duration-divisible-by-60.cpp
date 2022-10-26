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
