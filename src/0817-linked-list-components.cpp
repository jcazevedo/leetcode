// 817. Linked List Components
// https://leetcode.com/problems/linked-list-components/

#include <unordered_set>
#include <vector>

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
  int numComponents(ListNode* head, vector<int>& nums) {
    unordered_set<int> inNums;
    for (int num : nums) { inNums.insert(num); }
    int ans = 0;
    ListNode* curr = head;
    bool inComponent = false;
    while (curr != nullptr) {
      if (inNums.find(curr->val) != inNums.end()) {
        if (!inComponent) {
          inComponent = true;
          ++ans;
        }
      } else {
        inComponent = false;
      }
      curr = curr->next;
    }
    return ans;
  }
};
