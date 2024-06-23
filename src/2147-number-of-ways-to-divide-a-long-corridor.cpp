// 2147. Number of Ways to Divide a Long Corridor
// https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/

#include <string>
#include <vector>

using namespace std;

#define MOD 1000000007

class Solution {
 public:
  int numberOfWays(string corridor) {
    int N = corridor.size();
    int seatCount = 0, dividerCount = 0;
    vector<int> dividers;
    for (int i = 0; i < N; ++i) {
      if (corridor[i] == 'S') {
        if (seatCount > 0 && seatCount % 2 == 0) { dividers.push_back(dividerCount); }
        seatCount++;
        dividerCount = 0;
      } else {
        dividerCount++;
      }
    }
    if (seatCount == 0 || seatCount % 2) { return 0; }
    long long ans = 1;
    for (int d : dividers) { ans = (ans * (d + 1)) % MOD; }
    return ans;
  };
};
