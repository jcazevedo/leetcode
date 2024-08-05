// 92. Reverse Linked List II
// https://leetcode.com/problems/reverse-linked-list-ii/

#include <stack>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode* curr = head;
    int i = 1;
    stack<ListNode*> s;
    ListNode* prev = nullptr;
    while (curr != nullptr && i <= right) {
      if (i + 1 == left) { prev = curr; }
      if (i >= left) { s.push(curr); }
      curr = curr->next;
      i += 1;
    }
    ListNode* next = curr;
    curr = prev;
    if (curr == nullptr) {
      head = curr = s.top();
      s.pop();
    }
    while (!s.empty()) {
      curr->next = s.top();
      s.pop();
      curr = curr->next;
    }
    curr->next = next;
    return head;
  }
};
