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
  void insert_into_bst_aux(TreeNode* curr, int val) {
    if (val > curr->val) {
      if (curr->right == nullptr)
        curr->right = new TreeNode(val);
      else
        insert_into_bst_aux(curr->right, val);
    } else {
      if (curr->left == nullptr)
        curr->left = new TreeNode(val);
      else
        insert_into_bst_aux(curr->left, val);
    }
  }

 public:
  TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == nullptr) return new TreeNode(val);
    insert_into_bst_aux(root, val);
    return root;
  }
};
