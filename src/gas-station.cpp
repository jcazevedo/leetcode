#include <vector>

using namespace std;

class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int ans = 0, N = gas.size(), sum = 0;
    for (int i = 0; i < 2 * N; ++i) {
      sum += (gas[i % N] - cost[i % N]);
      if (sum < 0) {
        if (i + 1 >= N) return -1;
        sum = 0;
        ans = i + 1;
      }
    }
    return ans;
  }
};
