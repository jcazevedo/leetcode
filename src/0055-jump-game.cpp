// 55. Jump Game
// https://leetcode.com/problems/jump-game/

#include <vector>

using namespace std;

class Solution {
public:
  bool canJump(vector<int>& nums) {
    int N = nums.size();
    vector<int> max_j = vector<int>(N, 0);
    max_j[0] = nums[0];
    for (int i = 1; i < N; i++)
      max_j[i] = max(max_j[i - 1], i + nums[i]);
    int curr = 0;
    while (true) {
      int next = max_j[curr];
      if (next >= N - 1)
        return true;
      if (next == curr)
        return false;
      curr = next;
    }
    return false;
  }
};
