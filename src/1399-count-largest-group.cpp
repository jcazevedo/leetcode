// 1399. Count Largest Group
// https://leetcode.com/problems/count-largest-group/

#include <unordered_map>

using namespace std;

class Solution {
 public:
  int countLargestGroup(int n) {
    unordered_map<int, int> freq;
    for (int i = 1; i <= n; ++i) {
      int sum = 0, num = i;
      while (num) {
        sum += num % 10;
        num /= 10;
      }
      ++freq[sum];
    }
    int best = 0, ans = 0;
    for (unordered_map<int, int>::iterator itr = freq.begin(); itr != freq.end(); ++itr) {
      if (itr->second > best) {
        best = itr->second;
        ans = 1;
      } else if (itr->second == best) {
        ++ans;
      }
    }
    return ans;
  }
};
