#include <vector>

using namespace std;

class Solution {
private:
  vector<vector<int>> aux(vector<int>& nums, vector<bool>& used, int T) {
    vector<vector<int>> res;
    int N = nums.size();
    if (T == N) {
      vector<int> one = vector<int>();
      res.push_back(one);
      return res;
    }
    for (int i = 0; i < N; i++) {
      if (used[i])
        continue;
      used[i] = true;
      vector<vector<int>> other = aux(nums, used, T + 1);
      used[i] = false;
      for (auto itr = other.begin(); itr != other.end(); itr++) {
        itr->push_back(nums[i]);
        res.push_back(*itr);
      }
    }
    return res;
  }

public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<bool> used;
    used.assign(nums.size(), false);
    return aux(nums, used, 0);
  }
};
