// 2130. Maximum Twin Sum of a Linked List
// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/

#include <algorithm>

using namespace std;

#define MAXN 100000

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  int pairSum(ListNode* head) {
    int sums[MAXN];
    ListNode* slow = head;
    ListNode* fast = head;

    int n = 0;
    while (fast != nullptr) {
      sums[n++] = slow->val;
      slow = slow->next;
      fast = fast->next->next;
    }

    int ans = 0;
    while (n > 0) {
      sums[--n] += slow->val;
      ans = max(ans, sums[n]);
      slow = slow->next;
    }

    return ans;
  }
};
