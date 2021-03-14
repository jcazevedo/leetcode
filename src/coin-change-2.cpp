#include <vector>

using namespace std;

class Solution {
public:
  int change(int amount, vector<int>& coins) {
    int C = coins.size();
    vector<int> ways(amount + 1, 0);
    ways[0] = 1;
    for (int j = 0; j < C; ++j) {
      for (int i = 1; i <= amount; ++i) {
        if (i - coins[j] >= 0)
          ways[i] += ways[i - coins[j]];
      }
    }
    return ways[amount];
  }
};
