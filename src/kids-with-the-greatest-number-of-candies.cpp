#include <vector>

using namespace std;

class Solution {
 public:
  vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int N = candies.size();
    vector<bool> res(N, false);
    for (int i = 0; i < N; ++i) {
      res[i] = true;
      for (int j = 0; j < N; ++j) {
        if (i == j) continue;
        if (candies[i] + extraCandies < candies[j]) {
          res[i] = false;
          break;
        }
      }
    }
    return res;
  }
};
