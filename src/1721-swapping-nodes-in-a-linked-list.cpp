// 1721. Swapping Nodes in a Linked List
// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

#include <algorithm>

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
  ListNode* swapNodes(ListNode* head, int k) {
    ListNode* front = head;
    for (int i = 1; i < k; ++i) { front = front->next; }
    ListNode* back = head;
    ListNode* curr = front->next;
    while (curr != nullptr) {
      back = back->next;
      curr = curr->next;
    }
    swap(front->val, back->val);
    return head;
  }
};
