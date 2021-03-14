#include <map>
#include <set>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left),
                                                     right(right) {}
};

class Solution {
private:
  struct pair_compare {
    bool operator() (const pair<int, int>& l, const pair<int, int>& r) const {
      if (l.first != r.first)
        return l.first > r.first;
      return l.second < r.second;
    }
  };

  map<int, set<pair<int, int>, pair_compare>> vis;

  void dfs(TreeNode* curr, int x, int y) {
    if (curr == nullptr)
      return;
    vis[x].insert({y, curr->val});
    dfs(curr->left, x - 1, y - 1);
    dfs(curr->right, x + 1, y - 1);
  }

public:
  vector<vector<int>> verticalTraversal(TreeNode* root) {
    vis.clear();
    dfs(root, 0, 0);
    vector<vector<int>> ans = vector<vector<int>>(vis.size(), vector<int>());
    int idx = 0;
    for (auto itr = vis.begin(); itr != vis.end(); ++itr, ++idx) {
      for (auto itr2 = itr->second.begin(); itr2 != itr->second.end(); ++itr2) {
        ans[idx].push_back(itr2->second);
      }
    }
    return ans;
  }
};
