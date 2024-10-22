// 2583. Kth Largest Sum in a Binary Tree
// https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/

#include <algorithm>
#include <limits>
#include <queue>
#include <unordered_map>

using namespace std;

#ifdef LOCAL
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
#endif

class Solution {
 private:
  int levels = 0;
  unordered_map<int, long long> levelSum;

  void go(TreeNode* curr, int level) {
    levels = max(levels, level);
    levelSum[level] += curr->val;
    if (curr->left != nullptr) go(curr->left, level + 1);
    if (curr->right != nullptr) go(curr->right, level + 1);
  }

 public:
  long long kthLargestLevelSum(TreeNode* root, int k) {
    go(root, 1);
    if (levels < k) return -1;
    priority_queue<long long> pq;
    for (int level = 1; level <= levels; ++level) pq.push(levelSum[level]);
    long long ans = 0;
    while (k > 0) {
      ans = pq.top();
      pq.pop();
      --k;
    }
    return ans;
  }
};
