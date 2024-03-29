// 1356. Sort Integers by The Number of 1 Bits
// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 private:
  int bit_count(int num) {
    int ans = 0;
    while (num) {
      ans += (num & 1);
      num >>= 1;
    }
    return ans;
  }

 public:
  vector<int> sortByBits(vector<int>& arr) {
    vector<pair<int, int>> with_count;
    for (const int& num : arr) { with_count.emplace_back(bit_count(num), num); }
    sort(with_count.begin(), with_count.end());
    vector<int> ans;
    for (const pair<int, int>& p : with_count) { ans.push_back(p.second); }
    return ans;
  }
};
