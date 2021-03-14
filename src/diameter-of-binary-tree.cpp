#include <map>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
  map<TreeNode*, int> pathThrough;
  map<TreeNode*, int> pathEnding;

  int go(TreeNode* root) {
    if (root == nullptr) { return 0; }
    int best = 0;
    best = max(best, go(root->left));
    best = max(best, go(root->right));
    pathEnding[root] = 1 + max(pathEnding[root->left], pathEnding[root->right]);
    pathThrough[root] = 1 + pathEnding[root->left] + pathEnding[root->right];
    best = max(best, pathThrough[root] - 1);
    return best;
  }

public:
  int diameterOfBinaryTree(TreeNode* root) {
    pathThrough.clear();
    pathEnding.clear();
    pathThrough[nullptr] = 0;
    pathEnding[nullptr] = 0;
    return go(root);
  }
};
