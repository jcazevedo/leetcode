#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    vector<vector<int>> ans;
    if (root == nullptr) {
      return ans;
    }
    if (targetSum == root->val && root->left == nullptr && root->right == nullptr) {
      ans.push_back({root->val});
      return ans;
    }
    int next_sum = targetSum - root->val;
    vector<vector<int>> next_left = pathSum(root->left, next_sum);
    vector<vector<int>> next_right = pathSum(root->right, next_sum);
    for (vector<int> v : next_left) {
      v.insert(v.begin(), root->val);
      ans.push_back(v);
    }
    for (vector<int> v : next_right) {
      v.insert(v.begin(), root->val);
      ans.push_back(v);
    }
    return ans;
  }
};
