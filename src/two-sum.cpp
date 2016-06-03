class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    for (int i = 0; i < (int) nums.size(); i++) {
      for (int j = i + 1; j < (int) nums.size(); j++) {
        if (nums[i] + nums[j] == target) {
          res.push_back(i);
          res.push_back(j);
          return res;
        }
      }
    }
    return res;
  }
};
