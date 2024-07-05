// 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/

#include <algorithm>
#include <vector>

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
  vector<int> nodesBetweenCriticalPoints(ListNode *head) {
    int minD = -1;
    int maxD = -1;
    int prev = -1;
    int len = 0;
    int minC = -1;
    int prevC = -1;
    ListNode *curr = head;
    while (curr != nullptr) {
      bool isCritical =
          prev != -1 && curr->next != nullptr &&
          ((curr->val < prev && curr->val < curr->next->val) || (curr->val > prev && curr->val > curr->next->val));
      if (isCritical) {
        if (minC != -1) {
          maxD = len - minC;
        } else {
          minC = len;
        }
        if (prevC != -1) {
          if (minD == -1) {
            minD = len - prevC;
          } else {
            minD = min(minD, len - prevC);
          }
        }
        prevC = len;
      }
      prev = curr->val;
      curr = curr->next;
      ++len;
    }
    return {minD, maxD};
  }
};
