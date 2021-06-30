#include <queue>

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
  int widthOfBinaryTree(TreeNode *root) {
    if (root == nullptr)
      return 0;
    long long res = 0;
    queue<pair<TreeNode *, long long>> q;
    q.push(make_pair(root, 1L));
    while (!q.empty()) {
      int count = q.size();
      res = max(res, q.back().second - q.front().second + 1L);
      long long min_id = q.front().second;
      while (count--) {
        pair<TreeNode *, long long> curr = q.front();
        q.pop();
        long long id = curr.second - min_id + 1;
        if (curr.first->left != nullptr)
          q.emplace(curr.first->left, 2L * id);
        if (curr.first->right != nullptr)
          q.emplace(curr.first->right, 2L * id + 1L);
      }
    }
    return res;
  }
};
