#include <vector>

using namespace std;

class Solution {
public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int cnt = 0, best = 0;
    for (int v : nums) {
      if (v == 0)
        cnt = 0;
      else
        cnt++;
      best = max(best, cnt);
    }
    return best;
  }
};
