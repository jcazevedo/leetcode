#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
  vector<int> nodeToVal(const vector<TreeNode*>& v) {
    vector<int> res;
    int N = v.size();
    for (int i = 0; i < N; i++)
      res.push_back(v[i]->val);
    return res;
  }

public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (root == nullptr)
      return vector<vector<int>>();
    vector<vector<int>> res;
    vector<TreeNode*> curr, next;
    bool left = false;
    curr.push_back(root);
    while (!curr.empty()) {
      res.push_back(nodeToVal(curr));
      next.clear();
      int N = curr.size();
      for (int i = N - 1; i >= 0; i--) {
        TreeNode* n = curr[i];
        if (left) {
          if (n->left != nullptr)
            next.push_back(n->left);
          if (n->right != nullptr)
            next.push_back(n->right);
        } else {
          if (n->right != nullptr)
            next.push_back(n->right);
          if (n->left != nullptr)
            next.push_back(n->left);
        }
      }
      left = !left;
      curr = next;
    }
    return res;
  }
};
