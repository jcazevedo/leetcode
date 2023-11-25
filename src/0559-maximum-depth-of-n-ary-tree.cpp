// 559. Maximum Depth of N-ary Tree
// https://leetcode.com/problems/maximum-depth-of-n-ary-tree/

#include <vector>

using namespace std;

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
 public:
  int maxDepth(Node* root) {
    if (root == nullptr) return 0;
    int tot = 1;
    for (Node* child : root->children) tot = max(tot, 1 + maxDepth(child));
    return tot;
  }
};
