#include <vector>

using namespace std;

class Solution {
public:
  int maxScore(vector<int> &cardPoints, int k) {
    int N = cardPoints.size();
    vector<int> sum_left(N + 1, 0);
    vector<int> sum_right(N + 1, 0);
    for (int i = 1; i <= N; ++i)
      sum_left[i] = sum_left[i - 1] + cardPoints[i - 1];
    for (int i = 1; i <= N; ++i)
      sum_right[i] = sum_right[i - 1] + cardPoints[N - i];
    int best = INT_MIN;
    for (int take_left = 0; take_left <= k; ++take_left)
      best = max(best, sum_left[take_left] + sum_right[k - take_left]);
    return best;
  }
};
