#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
private:
  string vec_to_string(const vector<int>& v) {
    ostringstream ss;
    for (int num : v)
      ss << num << " ";
    return ss.str();
  }

  vector<int> string_to_vec(const string& s) {
    istringstream ss(s);
    vector<int> ans;
    int num;
    while (ss >> num)
      ans.push_back(num);
    return ans;
  }

  vector<int> tree_to_vec(TreeNode* root) {
    vector<int> ans;
    if (root != nullptr) {
      ans.push_back(root->val);
      vector<int> left = tree_to_vec(root->left);
      for (int num : left)
        ans.push_back(num);
      vector<int> right = tree_to_vec(root->right);
      for (int num : right)
        ans.push_back(num);
    }
    return ans;
  }

  TreeNode* vec_to_tree(vector<int> v) {
    if (v.empty())
      return nullptr;
    TreeNode* root = new TreeNode(v[0]);
    vector<int> left, right;
    int N = v.size();
    for (int i = 1; i < N; ++i) {
      if (v[i] <= v[0])
        left.push_back(v[i]);
      else
        right.push_back(v[i]);
    }
    root->left = vec_to_tree(left);
    root->right = vec_to_tree(right);
    return root;
  }

public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) { return vec_to_string(tree_to_vec(root)); }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) { return vec_to_tree(string_to_vec(data)); }
};
