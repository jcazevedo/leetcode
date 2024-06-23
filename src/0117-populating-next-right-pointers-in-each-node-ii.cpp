// 117. Populating Next Right Pointers in Each Node II
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

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
    Node* node = root;
    while (node != nullptr) {
      Node* curr = new Node(0);
      Node* level = curr;
      while (node != nullptr) {
        if (node->left) {
          curr->next = node->left;
          curr = curr->next;
        }
        if (node->right) {
          curr->next = node->right;
          curr = curr->next;
        }
        node = node->next;
      }
      node = level->next;
    }
    return root;
  }
};
