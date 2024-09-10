// 2326. Spiral Matrix IV
// https://leetcode.com/problems/spiral-matrix-iv/

#include <utility>
#include <vector>

using namespace std;

#ifdef LOCAL
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#endif

class Solution {
 private:
  static vector<pair<int, int>> dirs;

 public:
  vector<vector<int>> spiralMatrix(int m, int n, ListNode *head) {
    vector<vector<int>> ans(m, vector<int>(n, -1));
    int i = 0, j, dir = 1, curr = 1, W = n, H = m;
    for (j = 0; head != nullptr && j < W; ++j) {
      ans[i][j] = head->val;
      head = head->next;
    }
    --j;
    bool in_height = true;
    while (head != nullptr) {
      i += dirs[dir].first;
      j += dirs[dir].second;
      ans[i][j] = head->val;
      head = head->next;
      curr++;
      if (in_height && curr >= H) {
        dir = (dir + 1) % 4;
        H = H - 1;
        curr = 1;
        in_height = false;
      } else if (!in_height && curr >= W) {
        dir = (dir + 1) % 4;
        W = W - 1;
        curr = 1;
        in_height = true;
      }
    }
    return ans;
  }
};

vector<pair<int, int>> Solution::dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
