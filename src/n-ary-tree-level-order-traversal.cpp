#include <vector>

using namespace std;

// Definition for a Node.
class Node {
 public:
  int val;
  vector<Node*> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};

class Solution {
 private:
  vector<vector<int>> ans;
  void go(Node* node, int level) {
    if (node == nullptr) return;
    while (level >= (int)ans.size()) ans.push_back({});
    ans[level].push_back(node->val);
    for (Node* child : node->children) go(child, level + 1);
  }

 public:
  vector<vector<int>> levelOrder(Node* root) {
    ans.clear();
    go(root, 0);
    return ans;
  }
};
