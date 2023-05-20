#include <climits>
#include <map>

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
  pair<long long, long long> go(TreeNode* root) {
    if (root == nullptr)
      return {INT_MIN, INT_MIN};
    long long curr = root->val;
    pair<long long, long long> left = go(root->left);
    pair<long long, long long> right = go(root->right);
    long long best_ending = curr;
    best_ending = max(best_ending, max(curr + left.second, curr + right.second));
    long long best_through = best_ending;
    best_through = max(best_through, curr + left.second + right.second);
    return {max(left.first, max(right.first, best_through)), best_ending};
  }

public:
  int maxPathSum(TreeNode* root) { return go(root).first; }
};
