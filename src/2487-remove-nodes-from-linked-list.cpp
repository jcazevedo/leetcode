// 2487. Remove Nodes From Linked List
// https://leetcode.com/problems/remove-nodes-from-linked-list/

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
  ListNode* removeNodes(ListNode* head) {
    stack<ListNode*> s;
    ListNode* curr = head;
    while (curr != nullptr) {
      while (!s.empty() && s.top()->val < curr->val) s.pop();
      if (!s.empty()) s.top()->next = curr;
      s.push(curr);
      curr = curr->next;
    }
    ListNode* ans = nullptr;
    while (!s.empty()) {
      ans = s.top();
      s.pop();
    }
    return ans;
  }
};
