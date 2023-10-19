// 1361. Validate Binary Tree Nodes
// https://leetcode.com/problems/validate-binary-tree-nodes/

#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
    vector<int> inDegree(n);
    for (int u = 0; u < n; ++u) {
      if (leftChild[u] != -1) {
        inDegree[leftChild[u]]++;
        if (inDegree[leftChild[u]] > 1)
          return false;
      }
      if (rightChild[u] != -1) {
        inDegree[rightChild[u]]++;
        if (inDegree[rightChild[u]] > 1)
          return false;
      }
    }
    int root = -1;
    for (int u = 0; u < n; ++u)
      if (inDegree[u] == 0) {
        if (root != -1)
          return false;
        root = u;
      }
    if (root == -1)
      return false;
    vector<bool> seen(n);
    queue<int> q;
    q.push(root);
    seen[root] = true;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      if (leftChild[u] != -1) {
        int v = leftChild[u];
        if (seen[v])
          return false;
        seen[v] = true;
        q.push(v);
      }
      if (rightChild[u] != -1) {
        int v = rightChild[u];
        if (seen[v])
          return false;
        seen[v] = true;
        q.push(v);
      }
    }
    for (int u = 0; u < n; ++u)
      if (!seen[u])
        return false;
    return true;
  }
};
