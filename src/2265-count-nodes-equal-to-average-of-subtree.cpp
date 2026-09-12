// 2265. Count Nodes Equal to Average of Subtree
// https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/

#include <unordered_map>

using namespace std;

#ifdef LOCAL
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#endif

class Solution {
 private:
  int dfs(TreeNode *curr, unordered_map<TreeNode *, int> &cnt, unordered_map<TreeNode *, int> &sum) {
    cnt[curr] = 1;
    sum[curr] = curr->val;
    int ans = 0;
    if (curr->left != nullptr) {
      ans += dfs(curr->left, cnt, sum);
      cnt[curr] += cnt[curr->left];
      sum[curr] += sum[curr->left];
    }
    if (curr->right != nullptr) {
      ans += dfs(curr->right, cnt, sum);
      cnt[curr] += cnt[curr->right];
      sum[curr] += sum[curr->right];
    }
    if (sum[curr] / cnt[curr] == curr->val) { ++ans; }
    return ans;
  }

 public:
  int averageOfSubtree(TreeNode *root) {
    unordered_map<TreeNode *, int> cnt, sum;
    return dfs(root, cnt, sum);
  }
};
