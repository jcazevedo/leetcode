// 24. Swap Nodes in Pairs
// https://leetcode.com/problems/swap-nodes-in-pairs/

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* swapPairs(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
      return head;

    ListNode* ans = head->next;
    ListNode* curr = head;

    ListNode* next = swapPairs(curr->next->next);
    curr->next->next = curr;
    curr->next = next;

    return ans;
  }
};
