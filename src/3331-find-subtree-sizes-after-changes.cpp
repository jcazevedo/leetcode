// 3331. Find Subtree Sizes After Changes
// https://leetcode.com/problems/find-subtree-sizes-after-changes/

#include <string>
#include <vector>

using namespace std;

class Solution {
 private:
  void reparent(
      int node, const vector<vector<int>>& children, const string& s, vector<int>& last, vector<int>& newParent) {
    int character = s[node] - 'a';
    int previous = last[character];
    if (previous != -1) { newParent[node] = previous; }
    last[character] = node;
    for (int child : children[node]) { reparent(child, children, s, last, newParent); }
    last[character] = previous;
  }

  int subtreeSize(int node, const vector<vector<int>>& children, vector<int>& answer) {
    for (int child : children[node]) { answer[node] += subtreeSize(child, children, answer); }
    return answer[node];
  }

 public:
  vector<int> findSubtreeSizes(vector<int>& parent, string s) {
    int n = parent.size();
    vector<vector<int>> children(n);
    for (int i = 1; i < n; ++i) { children[parent[i]].push_back(i); }
    vector<int> newParent = parent;
    vector<int> last(26, -1);
    reparent(0, children, s, last, newParent);
    for (vector<int>& nodes : children) { nodes.clear(); }
    for (int i = 1; i < n; ++i) { children[newParent[i]].push_back(i); }
    vector<int> answer(n, 1);
    subtreeSize(0, children, answer);
    return answer;
  }
};
