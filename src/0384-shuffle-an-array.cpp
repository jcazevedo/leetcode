// 384. Shuffle an Array
// https://leetcode.com/problems/shuffle-an-array/

#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
private:
  vector<int> _nums;

public:
  Solution(vector<int>& nums) : _nums(nums) {}

  vector<int> reset() { return _nums; }

  vector<int> shuffle() {
    vector<int> ans = _nums;
    for (int i = 0; i < (int)ans.size(); ++i) {
      int rem = ans.size() - i;
      int next = i + (rand() % rem);
      swap(ans[i], ans[next]);
    }
    return ans;
  }
};
