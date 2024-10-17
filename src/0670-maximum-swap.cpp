// 670. Maximum Swap
// https://leetcode.com/problems/maximum-swap/description/

#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 private:
  vector<int> toDigits(int num) {
    vector<int> ans;
    while (num) {
      ans.push_back(num % 10);
      num /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }

 public:
  int maximumSwap(int num) {
    if (num == 0) { return 0; }
    vector<int> digits = toDigits(num);
    int N = digits.size();
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < N; ++i) { pq.push(make_pair(digits[i], i)); }
    bool swapped = false;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
      if (!swapped) {
        while (!pq.empty() && pq.top().second <= i) { pq.pop(); }
        if (!pq.empty() && pq.top().first > digits[i]) {
          swap(digits[i], digits[pq.top().second]);
          swapped = true;
        }
      }
      ans = ans * 10 + digits[i];
    }
    return ans;
  }
};
