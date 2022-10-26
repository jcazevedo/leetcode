// 1014. Best Sightseeing Pair
// https://leetcode.com/problems/best-sightseeing-pair/

#include <vector>

using namespace std;

class Solution {
 public:
  int maxScoreSightseeingPair(vector<int>& values) {
    int ans = 0;

    int best = values[0];
    for (int i = 1; i < (int)values.size(); ++i) {
      ans = max(ans, best + values[i] - i);
      if (values[i] + i > best) best = values[i] + i;
    }

    return ans;
  }
};
