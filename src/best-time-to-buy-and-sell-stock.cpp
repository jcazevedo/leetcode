#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    if (prices.empty())
      return 0;
    int N = prices.size();
    int min_so_far = prices[0];
    int best = 0;
    for (int i = 1; i < N; ++i) {
      best = max(best, prices[i] - min_so_far);
      min_so_far = min(min_so_far, prices[i]);
    }
    return best;
  }
};

