#include <algorithm>
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
  map<pair<TreeNode*, bool>, int> cache;

  int aux(TreeNode* root, bool can_rob) {
    if (root == nullptr) return 0;
    if (cache.find({root, can_rob}) == cache.end()) {
      int ans = 0;
      if (!can_rob) {
        ans += aux(root->left, true);
        ans += aux(root->right, true);
      } else {
        int rob_this = root->val;
        int dont_rob_this = 0;
        rob_this += aux(root->left, false);
        rob_this += aux(root->right, false);
        dont_rob_this += aux(root->left, true);
        dont_rob_this += aux(root->right, true);
        ans = max(rob_this, dont_rob_this);
      }
      cache[{root, can_rob}] = ans;
    }
    return cache[{root, can_rob}];
  }

 public:
  int rob(TreeNode* root) {
    cache.clear();
    return aux(root, true);
  }
};
