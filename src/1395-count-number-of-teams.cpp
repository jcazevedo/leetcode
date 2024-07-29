// 1395. Count Number of Teams
// https://leetcode.com/problems/count-number-of-teams/

#include <vector>

using namespace std;

class Solution {
 public:
  int numTeams(vector<int>& rating) {
    int N = rating.size();
    vector<int> largerL(N, 0);
    vector<int> largerR(N, 0);
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < i; ++j) {
        if (rating[j] > rating[i]) { ++largerL[i]; }
      }
      for (int j = i + 1; j < N; ++j) {
        if (rating[j] > rating[i]) { ++largerR[i]; }
      }
    }
    int ans = 0;
    for (int i = 0; i < N; ++i) {
      ans += largerL[i] * (N - i - 1 - largerR[i]);
      ans += (i - largerL[i]) * largerR[i];
    }
    return ans;
  }
};
