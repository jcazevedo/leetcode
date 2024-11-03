// 143. Reorder List
// https://leetcode.com/problems/reorder-list/

#include <stack>

using namespace std;

#ifdef LOCAL
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
#endif

class Solution {
 public:
  void reorderList(ListNode* head) {
    stack<ListNode*> s;
    ListNode* curr = head;
    while (curr) {
      s.push(curr);
      curr = curr->next;
    }
    curr = head;
    while (curr) {
      ListNode* prevCurr = curr->next;
      if (curr == s.top()) {
        curr->next = nullptr;
        break;
      }
      curr->next = s.top();
      s.pop();
      if (prevCurr == curr->next) {
        curr->next->next = nullptr;
        break;
      }
      curr->next->next = prevCurr;
      curr = prevCurr;
    }
  }
};
