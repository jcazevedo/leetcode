// 1658. Minimum Operations to Reduce X to Zero
// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int minOperations(vector<int>& nums, int x) {
    int n = nums.size();
    unordered_map<int, int> countR;
    int curr = 0;
    for (int i = n - 1; i >= 0; --i) {
      curr += nums[i];
      countR[curr] = n - i;
    }
    int best = -1;
    if (countR[x]) { best = countR[x]; }
    curr = 0;
    for (int i = 0; i < n; ++i) {
      curr += nums[i];
      if (curr == x && (best == -1 || i + 1 < best)) { best = i + 1; }
      if (countR[x - curr] && countR[x - curr] < n - i) {
        int next = i + 1 + countR[x - curr];
        if (best == -1 || next < best) { best = next; }
      }
    }
    return best;
  }
};
