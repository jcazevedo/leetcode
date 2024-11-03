// 138. Copy List with Random Pointer
// https://leetcode.com/problems/copy-list-with-random-pointer/

#include <unordered_map>

using namespace std;

#ifdef LOCAL
class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = nullptr;
    random = nullptr;
  }
};
#endif

class Solution {
 public:
  Node* copyRandomList(Node* head) {
    if (head == nullptr) { return nullptr; }
    unordered_map<Node*, Node*> copies;
    Node* curr = head;
    while (curr != nullptr) {
      Node* copy = new Node(curr->val);
      copy->next = curr->next;
      copy->random = curr->random;
      copies[curr] = copy;
      curr = curr->next;
    }
    curr = copies[head];
    while (curr != nullptr) {
      if (curr->next != nullptr) { curr->next = copies[curr->next]; }
      if (curr->random != nullptr) { curr->random = copies[curr->random]; }
      curr = curr->next;
    }
    return copies[head];
  }
};
