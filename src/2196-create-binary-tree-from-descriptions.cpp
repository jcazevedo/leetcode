// 2196. Create Binary Tree From Descriptions
// https://leetcode.com/problems/create-binary-tree-from-descriptions/

#include <unordered_map>
#include <unordered_set>
#include <vector>

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
  TreeNode *createBinaryTree(vector<vector<int>> &descriptions) {
    unordered_map<int, TreeNode *> nodes;
    unordered_set<int> possibleRoots;
    for (const vector<int> &description : descriptions) {
      int parent = description[0];
      int child = description[1];
      bool isLeft = description[2];
      if (nodes.find(parent) == nodes.end()) {
        nodes[parent] = new TreeNode(parent);
        possibleRoots.insert(parent);
      }
      if (nodes.find(child) == nodes.end()) nodes[child] = new TreeNode(child);
      possibleRoots.erase(child);
      if (isLeft)
        nodes[parent]->left = nodes[child];
      else
        nodes[parent]->right = nodes[child];
    }
    return nodes[*possibleRoots.begin()];
  }
};
