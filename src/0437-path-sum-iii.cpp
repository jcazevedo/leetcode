// 437. Path Sum III
// https://leetcode.com/problems/path-sum-iii/

#include <unordered_map>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
 private:
  unordered_map<int, int> sums;

  int n_paths(TreeNode* curr, int target_sum, int curr_sum) {
    if (curr == nullptr) return 0;
    int ans = 0;
    curr_sum += curr->val;
    if (curr_sum == target_sum) ans++;
    ans += sums[curr_sum - target_sum];
    sums[curr_sum]++;
    ans += n_paths(curr->left, target_sum, curr_sum);
    ans += n_paths(curr->right, target_sum, curr_sum);
    sums[curr_sum]--;
    return ans;
  }

 public:
  int pathSum(TreeNode* root, int sum) {
    sums.clear();
    return n_paths(root, sum, 0);
  }
};
