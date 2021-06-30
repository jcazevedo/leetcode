#include <stack>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;

  ListNode() : val(0), next(nullptr) {}

  ListNode(int x) : val(x), next(nullptr) {}

  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    stack<ListNode *> s1, s2;
    while (l1 != nullptr) {
      s1.push(l1);
      l1 = l1->next;
    }
    while (l2 != nullptr) {
      s2.push(l2);
      l2 = l2->next;
    }
    int carry = 0;
    ListNode *prev = nullptr;
    while (!s1.empty() || !s2.empty()) {
      int v1 = 0;
      if (!s1.empty()) {
        v1 = s1.top()->val;
        s1.pop();
      }
      int v2 = 0;
      if (!s2.empty()) {
        v2 = s2.top()->val;
        s2.pop();
      }
      int res = v1 + v2 + carry;
      carry = res / 10;
      res = res % 10;
      ListNode *curr = new ListNode(res);
      curr->next = prev;
      prev = curr;
    }
    if (carry) {
      ListNode *curr = new ListNode(carry);
      curr->next = prev;
      prev = curr;
    }
    return prev;
  }
};
