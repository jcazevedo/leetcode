#include <vector>

using namespace std;

class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    int C = coins.size();
    vector<int> ways;
    ways.assign(amount + 1, -1);
    ways[0] = 0;
    for (int i = 1; i <= amount; i++) {
      for (int j = 0; j < C; j++) {
        if (i - coins[j] >= 0 && ways[i - coins[j]] != -1) {
          if (ways[i] == -1 || ways[i - coins[j]] + 1 < ways[i])
            ways[i] = ways[i - coins[j]] + 1;
        }
      }
    }
    return ways[amount];
  }
};
