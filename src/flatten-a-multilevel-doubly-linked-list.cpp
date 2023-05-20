class Node {
public:
  int val;
  Node* prev;
  Node* next;
  Node* child;
};

class Solution {
public:
  Node* flatten(Node* head) {
    if (head == nullptr)
      return head;
    Node* curr = head;
    while (curr != nullptr) {
      if (curr->child) {
        Node* next = curr->next;
        Node* child = flatten(curr->child);
        child->prev = curr;
        curr->next = child;
        while (child->next)
          child = child->next;
        child->next = next;
        if (next)
          next->prev = child;
        curr->child = nullptr;
      }
      curr = curr->next;
    }
    return head;
  }
};
