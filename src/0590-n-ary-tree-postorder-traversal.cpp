// 590. N-ary Tree Postorder Traversal
// https://leetcode.com/problems/n-ary-tree-postorder-traversal/

#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

#ifdef LOCAL
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
#endif

class Solution {
 public:
  vector<int> postorder(Node* root) {
    vector<int> ans;
    if (root == nullptr) { return ans; }
    stack<Node*> s;
    s.push(root);
    while (!s.empty()) {
      Node* curr = s.top();
      s.pop();
      ans.push_back(curr->val);
      for (Node* next : curr->children) { s.push(next); }
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
