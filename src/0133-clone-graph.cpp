// 133. Clone Graph
// https://leetcode.com/problems/clone-graph/

#include <unordered_map>
#include <vector>

using namespace std;

class Node {
public:
  int val;
  vector<Node*> neighbors;

  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }

  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }

  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
private:
  unordered_map<Node*, Node*> copies;

  Node* copy(Node* node) {
    Node* curr = new Node(node->val);
    copies[node] = curr;
    for (Node* neighbor : node->neighbors) {
      if (copies.count(neighbor) == 0) {
        curr->neighbors.push_back(copy(neighbor));
      } else {
        curr->neighbors.push_back(copies[neighbor]);
      }
    }
    return curr;
  }

public:
  Node* cloneGraph(Node* node) {
    if (node != nullptr)
      return copy(node);
    return nullptr;
  }
};
