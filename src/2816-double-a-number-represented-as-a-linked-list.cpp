// 2816. Double a Number Represented as a Linked List
// https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/

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
  ListNode* doubleIt(ListNode* head) {
    stack<ListNode*> s;
    ListNode* curr = head;
    while (curr != nullptr) {
      s.push(curr);
      curr = curr->next;
    }
    int carry = 0;
    while (!s.empty()) {
      ListNode* top = s.top();
      s.pop();
      top->val = top->val * 2 + carry;
      carry = top->val / 10;
      top->val = top->val % 10;
    }
    if (carry) {
      ListNode* newHead = new ListNode(carry);
      newHead->next = head;
      return newHead;
    }
    return head;
  }
};
