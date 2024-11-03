// 135. Candy
// https://leetcode.com/problems/candy/

#include <vector>

using namespace std;

class Solution {
 public:
  int candy(vector<int>& ratings) {
    int N = ratings.size();
    vector<int> assignment(N, 1);
    for (int i = 1; i < N; ++i) {
      if (ratings[i] > ratings[i - 1]) { assignment[i] = assignment[i - 1] + 1; }
    }
    for (int i = N - 2; i >= 0; --i) {
      if (ratings[i] > ratings[i + 1] && assignment[i] <= assignment[i + 1]) { assignment[i] = assignment[i + 1] + 1; }
    }
    int ans = 0;
    for (int i = 0; i < N; ++i) { ans += assignment[i]; }
    return ans;
  }
};
