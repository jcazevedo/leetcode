// 116. Populating Next Right Pointers in Each Node
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val, Node* _left, Node* _right, Node* _next) : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
 public:
  Node* connect(Node* root) {
    if (root == nullptr) return root;
    Node* level = root;
    while (level->left) {
      Node* curr = level;
      while (curr) {
        curr->left->next = curr->right;
        if (curr->next) curr->right->next = curr->next->left;
        curr = curr->next;
      }
      level = level->left;
    }
    return root;
  }
};
