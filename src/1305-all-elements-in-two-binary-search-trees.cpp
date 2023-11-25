// 1305. All Elements in Two Binary Search Trees
// https://leetcode.com/problems/all-elements-in-two-binary-search-trees/

#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
private:
  void in_order_traverse(TreeNode* curr, vector<int>& list) {
    if (curr != nullptr) {
      in_order_traverse(curr->left, list);
      list.push_back(curr->val);
      in_order_traverse(curr->right, list);
    }
  }

public:
  vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    vector<int> list1, list2;
    in_order_traverse(root1, list1);
    in_order_traverse(root2, list2);
    vector<int> ans;
    int N1 = list1.size(), N2 = list2.size(), i1 = 0, i2 = 0;
    while (i1 < N1 || i2 < N2) {
      if (i1 >= N1)
        ans.push_back(list2[i2++]);
      else if (i2 >= N2)
        ans.push_back(list1[i1++]);
      else if (list1[i1] < list2[i2])
        ans.push_back(list1[i1++]);
      else
        ans.push_back(list2[i2++]);
    }
    return ans;
  }
};
